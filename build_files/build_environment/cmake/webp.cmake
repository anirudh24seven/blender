# Note the utility apps may use png/tiff/gif system libraries, but the
# library itself does not depend on them, so should give no problems.

set(WEBP_EXTRA_ARGS
  -DWEBP_HAVE_SSE2=ON
  -DWEBP_HAVE_SSE41=OFF
  -DWEBP_HAVE_AVX2=OFF
)

if(WIN32)
  set(WEBP_BUILD_DIR ${BUILD_MODE}/)
else()
  set(WEBP_BUILD_DIR)
endif()

ExternalProject_Add(external_webp
  URL ${WEBP_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH MD5=${WEBP_HASH}
  PREFIX ${BUILD_DIR}/webp
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${LIBDIR}/webp -Wno-dev ${DEFAULT_CMAKE_FLAGS} ${WEBP_EXTRA_ARGS}
  INSTALL_DIR ${LIBDIR}/webp
)

if(WIN32)
  if(BUILD_MODE STREQUAL Release)
    ExternalProject_Add_Step(external_webp after_install
      COMMAND ${CMAKE_COMMAND} -E copy_directory ${LIBDIR}/webp ${HARVEST_TARGET}/webp
      DEPENDEES install
    )
  endif()
endif()
