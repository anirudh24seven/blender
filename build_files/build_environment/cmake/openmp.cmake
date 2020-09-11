ExternalProject_Add(external_openmp
  URL ${OPENMP_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH MD5=${OPENMP_HASH}
  PREFIX ${BUILD_DIR}/openmp
  PATCH_COMMAND ${PATCH_CMD} -p 1 -d ${BUILD_DIR}/openmp/src/external_openmp < ${PATCH_DIR}/openmp.diff
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${LIBDIR}/openmp ${DEFAULT_CMAKE_FLAGS}
  INSTALL_COMMAND cd ${BUILD_DIR}/openmp/src/external_openmp-build && install_name_tool -id @executable_path/../Resources/lib/libomp.dylib runtime/src/libomp.dylib && make install
  INSTALL_DIR ${LIBDIR}/openmp
)

add_dependencies(
  external_openmp
  external_clang
)
