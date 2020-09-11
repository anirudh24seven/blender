ExternalProject_Add(external_nasm
  URL ${NASM_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH SHA256=${NASM_HASH}
  PREFIX ${BUILD_DIR}/nasm
  PATCH_COMMAND ${PATCH_CMD} --verbose -p 1 -N -d ${BUILD_DIR}/nasm/src/external_nasm < ${PATCH_DIR}/nasm.diff
  CONFIGURE_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/nasm/src/external_nasm/ && ${CONFIGURE_COMMAND} --prefix=${LIBDIR}/nasm
  BUILD_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/nasm/src/external_nasm/ && make -j${MAKE_THREADS}
  INSTALL_COMMAND ${CONFIGURE_ENV} && cd ${BUILD_DIR}/nasm/src/external_nasm/ && make install
  INSTALL_DIR ${LIBDIR}/nasm
)
