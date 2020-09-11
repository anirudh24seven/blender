ExternalProject_Add(external_python_site_packages
  DOWNLOAD_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  PREFIX ${BUILD_DIR}/site_packages
  INSTALL_COMMAND ${PYTHON_BINARY} -m pip install idna==${IDNA_VERSION} chardet==${CHARDET_VERSION} urllib3==${URLLIB3_VERSION} certifi==${CERTIFI_VERSION} requests==${REQUESTS_VERSION} --no-binary :all:
)

add_dependencies(
  external_python_site_packages
  external_python
)
