if(WIN32)
  set(X264_EXTRA_ARGS --enable-win32thread --cross-prefix=${MINGW_HOST}- --host=${MINGW_HOST})
endif()


if(APPLE)
  if("${CMAKE_OSX_ARCHITECTURES}" STREQUAL "arm64")
    set(X264_EXTRA_ARGS ${X264_EXTRA_ARGS} "--disable-asm")
    set(X264_CONFIGURE_ENV echo .)
  else()
    set(X264_CONFIGURE_ENV
      export AS=${LIBDIR}/nasm/bin/nasm
    )
  endif()
else()
  set(X264_CONFIGURE_ENV echo .)
endif()

ExternalProject_Add(external_x264
  URL ${X264_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH SHA256=${X264_HASH}
  PREFIX ${BUILD_DIR}/x264
  CONFIGURE_COMMAND ${CONFIGURE_ENV} && ${X264_CONFIGURE_ENV} && cd ${BUILD_DIR}/x264/src/external_x264/ &&
    ${CONFIGURE_COMMAND} --prefix=${LIBDIR}/x264
    --enable-static
    --enable-pic
    --disable-lavf
    ${X264_EXTRA_ARGS}
  BUILD_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/x264/src/external_x264/ && make -j${MAKE_THREADS}
  INSTALL_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/x264/src/external_x264/ && make install
  INSTALL_DIR ${LIBDIR}/x264
)

if(MSVC)
  set_target_properties(external_x264 PROPERTIES FOLDER Mingw)
endif()

if(APPLE)
  add_dependencies(
    external_x264
    external_nasm
  )
endif()
