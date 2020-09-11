set(LZMA_PATCH_CMD echo .)

ExternalProject_Add(external_lzma
  URL ${LZMA_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH SHA256=${LZMA_HASH}
  PREFIX ${BUILD_DIR}/lzma
  PATCH_COMMAND ${LZMA_PATCH_CMD}
  CONFIGURE_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/lzma/src/external_lzma/ && ${CONFIGURE_COMMAND} --prefix=${LIBDIR}/lzma
    --disable-shared
  BUILD_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/lzma/src/external_lzma/ && make -j${MAKE_THREADS}
  INSTALL_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/lzma/src/external_lzma/ && make install
  INSTALL_DIR ${LIBDIR}/lzma
)
