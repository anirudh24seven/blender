if(WIN32)
  set(SDL_EXTRA_ARGS
    -DSDL_STATIC=Off
  )
else()
  set(SDL_EXTRA_ARGS
    -DSDL_STATIC=ON
    -DSDL_SHARED=OFF
    -DSDL_VIDEO=OFF
    -DSNDIO=OFF
  )
endif()

ExternalProject_Add(external_sdl
  URL ${SDL_URI}
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
  URL_HASH MD5=${SDL_HASH}
  PREFIX ${BUILD_DIR}/sdl
  PATCH_COMMAND ${PATCH_CMD} -p 0 -N -d ${BUILD_DIR}/sdl/src/external_sdl < ${PATCH_DIR}/sdl.diff
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${LIBDIR}/sdl ${DEFAULT_CMAKE_FLAGS} ${SDL_EXTRA_ARGS}
  INSTALL_DIR ${LIBDIR}/sdl
)

if(BUILD_MODE STREQUAL Release AND WIN32)
  ExternalProject_Add_Step(external_sdl after_install
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${LIBDIR}/sdl/include/sdl2 ${HARVEST_TARGET}/sdl/include
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${LIBDIR}/sdl/lib ${HARVEST_TARGET}/sdl/lib
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${LIBDIR}/sdl/bin ${HARVEST_TARGET}/sdl/lib
    DEPENDEES install
  )
endif()
