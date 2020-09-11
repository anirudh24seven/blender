if(MSVC)
  message("BIN >${PYTHON_BINARY}<")
  if(BUILD_MODE STREQUAL Debug)
    set(NUMPY_DIR_POSTFIX -pydebug)
    set(NUMPY_ARCHIVE_POSTFIX d)
    set(NUMPY_BUILD_OPTION --debug)
  else()
    set(NUMPY_DIR_POSTFIX)
    set(NUMPY_ARCHIVE_POSTFIX)
    set(NUMPY_BUILD_OPTION)
  endif()
endif()

set(NUMPY_POSTFIX)

ExternalProject_Add(external_numpy
  URL ${NUMPY_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH MD5=${NUMPY_HASH}
  PREFIX ${BUILD_DIR}/numpy
  PATCH_COMMAND ${NUMPY_PATCH}
  CONFIGURE_COMMAND ""
  PATCH_COMMAND COMMAND ${PATCH_CMD} -p 1 -d ${BUILD_DIR}/numpy/src/external_numpy < ${PATCH_DIR}/numpy.diff
  LOG_BUILD 1
  BUILD_COMMAND ${PYTHON_BINARY} ${BUILD_DIR}/numpy/src/external_numpy/setup.py build ${NUMPY_BUILD_OPTION} install --old-and-unmanageable
  INSTALL_COMMAND ""
)

add_dependencies(
  external_numpy
  external_python
)
