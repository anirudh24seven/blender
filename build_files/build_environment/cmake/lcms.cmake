set(LCMS_EXTRA_ARGS
)

ExternalProject_Add(external_lcms
  URL ${LCMS_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH MD5=${LCMS_HASH}
  PREFIX ${BUILD_DIR}/lcms
  # Patch taken from ocio.
  PATCH_COMMAND ${CMAKE_COMMAND} -E copy ${PATCH_DIR}/cmakelists_lcms.txt ${BUILD_DIR}/lcms/src/external_lcms/CMakeLists.txt
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${LIBDIR}/lcms ${DEFAULT_CMAKE_FLAGS} ${LCMS_EXTRA_ARGS}
  INSTALL_DIR ${LIBDIR}/lcms
)
