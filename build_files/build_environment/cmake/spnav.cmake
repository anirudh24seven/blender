ExternalProject_Add(external_spnav
  URL ${SPNAV_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH MD5=${SPNAV_HASH}
  PREFIX ${BUILD_DIR}/spnav
  CONFIGURE_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/spnav/src/external_spnav/ && ${CONFIGURE_COMMAND} --prefix=${LIBDIR}/spnav --disable-shared --enable-static --with-pic
  BUILD_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/spnav/src/external_spnav/ && make -j${MAKE_THREADS}
  INSTALL_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/spnav/src/external_spnav/ && make install
  INSTALL_DIR ${LIBDIR}/spnav
)
