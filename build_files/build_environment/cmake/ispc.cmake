if(WIN32)
  set(ISPC_EXTRA_ARGS_WIN
    -DFLEX_EXECUTABLE=${LIBDIR}/flexbison/win_flex.exe
    -DBISON_EXECUTABLE=${LIBDIR}/flexbison/win_bison.exe
    -DM4_EXECUTABLE=${DOWNLOAD_DIR}/mingw/mingw64/msys/1.0/bin/m4.exe
  )
elseif(APPLE)
  # Use bison installed via Homebrew.
  # The one which comes which Xcode toolset is too old.
  set(ISPC_EXTRA_ARGS_APPLE
    -DBISON_EXECUTABLE=/usr/local/opt/bison/bin/bison
  )
elseif(UNIX)
  set(ISPC_EXTRA_ARGS_UNIX
    -DCMAKE_C_COMPILER=${LIBDIR}/clang/bin/clang
    -DCMAKE_CXX_COMPILER=${LIBDIR}/clang/bin/clang++
  )
endif()

set(ISPC_EXTRA_ARGS
    -DARM_ENABLED=Off
    -DISPC_NO_DUMPS=On
    -DISPC_INCLUDE_EXAMPLES=Off
    -DISPC_INCLUDE_TESTS=Off
    -DLLVM_ROOT=${LIBDIR}/llvm/lib/cmake/llvm
    -DLLVM_LIBRARY_DIR=${LIBDIR}/llvm/lib
    -DCLANG_EXECUTABLE=${LIBDIR}/clang/bin/clang
    -DISPC_INCLUDE_TESTS=Off
    -DCLANG_LIBRARY_DIR=${LIBDIR}/clang/lib
    -DCLANG_INCLUDE_DIRS=${LIBDIR}/clang/include
    ${ISPC_EXTRA_ARGS_WIN}
    ${ISPC_EXTRA_ARGS_APPLE}
    ${ISPC_EXTRA_ARGS_UNIX}
)

ExternalProject_Add(external_ispc
  URL ${ISPC_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH MD5=${ISPC_HASH}
  PREFIX ${BUILD_DIR}/ispc
  PATCH_COMMAND ${PATCH_CMD} -p 1 -d ${BUILD_DIR}/ispc/src/external_ispc < ${PATCH_DIR}/ispc.diff
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${LIBDIR}/ispc -Wno-dev ${DEFAULT_CMAKE_FLAGS} ${ISPC_EXTRA_ARGS} ${BUILD_DIR}/ispc/src/external_ispc
  INSTALL_DIR ${LIBDIR}/ispc
)

add_dependencies(
  external_ispc
  ll
  external_clang
)

if(WIN32)
  add_dependencies(
    external_ispc
    external_flexbison
  )
endif()
