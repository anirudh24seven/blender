set(PUGIXML_EXTRA_ARGS
)

ExternalProject_Add(external_pugixml
  URL ${PUGIXML_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH MD5=${PUGIXML_HASH}
  PREFIX ${BUILD_DIR}/pugixml
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${LIBDIR}/pugixml ${DEFAULT_CMAKE_FLAGS} ${PUGIXML_EXTRA_ARGS}
  INSTALL_DIR ${LIBDIR}/pugixml
)
if(WIN32)
  if(BUILD_MODE STREQUAL Release)
    ExternalProject_Add_Step(external_pugixml after_install
      COMMAND ${CMAKE_COMMAND} -E copy ${LIBDIR}/pugixml/lib/pugixml.lib ${HARVEST_TARGET}/osl/lib/pugixml.lib
      DEPENDEES install
    )
  endif()
  if(BUILD_MODE STREQUAL Debug)
    ExternalProject_Add_Step(external_pugixml after_install
      COMMAND ${CMAKE_COMMAND} -E copy ${LIBDIR}/pugixml/lib/pugixml.lib ${HARVEST_TARGET}/osl/lib/pugixml_d.lib
      DEPENDEES install
    )
  endif()
endif()
