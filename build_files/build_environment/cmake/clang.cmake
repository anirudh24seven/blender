set(CLANG_EXTRA_ARGS
  -DCLANG_PATH_TO_LLVM_SOURCE=${BUILD_DIR}/ll/src/ll
  -DCLANG_PATH_TO_LLVM_BUILD=${LIBDIR}/llvm
  -DLLVM_USE_CRT_RELEASE=MD
  -DLLVM_USE_CRT_DEBUG=MDd
  -DLLVM_CONFIG=${LIBDIR}/llvm/bin/llvm-config
)

if(WIN32)
  set(CLANG_GENERATOR "Ninja")
else()
  set(CLANG_GENERATOR "Unix Makefiles")
endif()

if(APPLE)
  set(CLANG_EXTRA_ARGS ${CLANG_EXTRA_ARGS}
    -DLIBXML2_LIBRARY=${LIBDIR}/xml2/lib/libxml2.a
  )
endif()

ExternalProject_Add(external_clang
  URL ${CLANG_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH MD5=${CLANG_HASH}
  PREFIX ${BUILD_DIR}/clang
  CMAKE_GENERATOR ${CLANG_GENERATOR}
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${LIBDIR}/clang ${DEFAULT_CMAKE_FLAGS} ${CLANG_EXTRA_ARGS}
  INSTALL_DIR ${LIBDIR}/clang
)

if(MSVC)
  if(BUILD_MODE STREQUAL Release)
    set(CLANG_HARVEST_COMMAND ${CMAKE_COMMAND} -E copy_directory ${LIBDIR}/clang/ ${HARVEST_TARGET}/llvm/)
  else()
    set(CLANG_HARVEST_COMMAND
      ${CMAKE_COMMAND} -E copy_directory ${LIBDIR}/clang/lib/ ${HARVEST_TARGET}/llvm/debug/lib/
    )
  endif()
  ExternalProject_Add_Step(external_clang after_install
    COMMAND ${CLANG_HARVEST_COMMAND}
    DEPENDEES mkdir update patch download configure build install
  )
endif()

add_dependencies(
  external_clang
  ll
)
