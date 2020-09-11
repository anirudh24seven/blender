ExternalProject_Add(external_jemalloc
  URL ${JEMALLOC_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH MD5=${JEMALLOC_HASH}
  PREFIX ${BUILD_DIR}/jemalloc
  CONFIGURE_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/jemalloc/src/external_jemalloc/ && ${CONFIGURE_COMMAND} --prefix=${LIBDIR}/jemalloc --disable-shared --enable-static --with-pic
  BUILD_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/jemalloc/src/external_jemalloc/ && make -j${MAKE_THREADS}
  INSTALL_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/jemalloc/src/external_jemalloc/ && make install
  INSTALL_DIR ${LIBDIR}/jemalloc
)
