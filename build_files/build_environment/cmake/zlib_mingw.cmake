ExternalProject_Add(external_zlib_mingw
  URL ${ZLIB_URI}
  URL_HASH MD5=${ZLIB_HASH}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  PREFIX ${BUILD_DIR}/zlib_mingw
  CONFIGURE_COMMAND echo .
  BUILD_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/zlib_mingw/src/external_zlib_mingw/ && make -f win32/makefile.gcc -j${MAKE_THREADS}
  INSTALL_COMMAND echo .
  INSTALL_DIR ${LIBDIR}/zlib_mingw
)

if(BUILD_MODE STREQUAL Release)
  ExternalProject_Add_Step(external_zlib_mingw after_install
    COMMAND ${CMAKE_COMMAND} -E copy ${BUILD_DIR}/zlib_mingw/src/external_zlib_mingw/libz.a ${LIBDIR}/zlib/lib/z.lib
    DEPENDEES install
  )
endif()

if(MSVC)
  set_target_properties(external_zlib_mingw PROPERTIES FOLDER Mingw)
endif()
