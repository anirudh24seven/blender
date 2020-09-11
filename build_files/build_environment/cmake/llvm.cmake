if(APPLE AND "${CMAKE_OSX_ARCHITECTURES}" STREQUAL "arm64")
  set(LLVM_TARGETS AArch64)
else()
  set(LLVM_TARGETS X86)
endif()

set(LLVM_EXTRA_ARGS
  -DLLVM_USE_CRT_RELEASE=MD
  -DLLVM_USE_CRT_DEBUG=MDd
  -DLLVM_INCLUDE_TESTS=OFF
  -DLLVM_TARGETS_TO_BUILD=${LLVM_TARGETS}
  -DLLVM_INCLUDE_EXAMPLES=OFF
  -DLLVM_ENABLE_TERMINFO=OFF
  -DLLVM_BUILD_LLVM_C_DYLIB=OFF
  -DLLVM_ENABLE_UNWIND_TABLES=OFF
)

if(WIN32)
  set(LLVM_GENERATOR "Ninja")
else()
  set(LLVM_GENERATOR "Unix Makefiles")
endif()

# short project name due to long filename issues on windows
ExternalProject_Add(ll
  URL ${LLVM_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH MD5=${LLVM_HASH}
  CMAKE_GENERATOR ${LLVM_GENERATOR}
  PREFIX ${BUILD_DIR}/ll
  PATCH_COMMAND ${PATCH_CMD} -p 1 -d ${BUILD_DIR}/ll/src/ll < ${PATCH_DIR}/llvm.diff
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${LIBDIR}/llvm ${DEFAULT_CMAKE_FLAGS} ${LLVM_EXTRA_ARGS}
  INSTALL_DIR ${LIBDIR}/llvm
)

if(MSVC)
  if(BUILD_MODE STREQUAL Release)
    set(LLVM_HARVEST_COMMAND ${CMAKE_COMMAND} -E copy_directory ${LIBDIR}/llvm/ ${HARVEST_TARGET}/llvm/ )
  else()
    set(LLVM_HARVEST_COMMAND
      ${CMAKE_COMMAND} -E copy_directory ${LIBDIR}/llvm/lib/ ${HARVEST_TARGET}/llvm/debug/lib/ &&
      ${CMAKE_COMMAND} -E copy_directory ${LIBDIR}/llvm/include/ ${HARVEST_TARGET}/llvm/debug/include/
    )
  endif()
  ExternalProject_Add_Step(ll after_install
    COMMAND ${LLVM_HARVEST_COMMAND}
    DEPENDEES mkdir update patch download configure build install
  )
endif()
