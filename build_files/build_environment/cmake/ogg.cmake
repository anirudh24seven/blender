ExternalProject_Add(external_ogg
  URL ${OGG_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH SHA256=${OGG_HASH}
  PREFIX ${BUILD_DIR}/ogg
  PATCH_COMMAND ${PATCH_CMD} --verbose -p 1 -N -d ${BUILD_DIR}/ogg/src/external_ogg < ${PATCH_DIR}/ogg.diff
  CONFIGURE_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/ogg/src/external_ogg/ && ${CONFIGURE_COMMAND} --prefix=${LIBDIR}/ogg --disable-shared --enable-static
  BUILD_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/ogg/src/external_ogg/ && make -j${MAKE_THREADS}
  INSTALL_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/ogg/src/external_ogg/ && make install
  INSTALL_DIR ${LIBDIR}/ogg
)

if(MSVC)
  set_target_properties(external_ogg PROPERTIES FOLDER Mingw)
endif()
