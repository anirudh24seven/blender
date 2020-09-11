set(GLEW_EXTRA_ARGS
  -DBUILD_UTILS=Off
  -DBUILD_SHARED_LIBS=Off
)

ExternalProject_Add(external_glew
  URL ${GLEW_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH MD5=${GLEW_HASH}
  PATCH_COMMAND COMMAND ${CMAKE_COMMAND} -E copy ${PATCH_DIR}/cmakelists_glew.txt ${BUILD_DIR}/glew/src/external_glew/CMakeLists.txt
  PREFIX ${BUILD_DIR}/glew
  CMAKE_ARGS -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DCMAKE_INSTALL_PREFIX=${LIBDIR}/glew ${DEFAULT_CMAKE_FLAGS} ${GLEW_EXTRA_ARGS}
  INSTALL_DIR ${LIBDIR}/glew
)
