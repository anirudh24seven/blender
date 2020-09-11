set(TINYXML_EXTRA_ARGS
)

ExternalProject_Add(external_tinyxml
  URL ${TINYXML_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH MD5=${TINYXML_HASH}
  PREFIX ${BUILD_DIR}/tinyxml
  # patch taken from ocio
  PATCH_COMMAND ${PATCH_CMD} -p 1 -N -d ${BUILD_DIR}/tinyxml/src/external_tinyxml < ${PATCH_DIR}/tinyxml.diff
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${LIBDIR}/tinyxml ${DEFAULT_CMAKE_FLAGS} ${TINYXML_EXTRA_ARGS}
  INSTALL_DIR ${LIBDIR}/tinyxml
)
