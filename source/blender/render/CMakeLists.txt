set(INC
  extern/include
  intern/include
  ../blenkernel
  ../blenlib
  ../blentranslation
  ../depsgraph
  ../draw
  ../gpu
  ../imbuf
  ../makesdna
  ../makesrna
  ../nodes
  ../simulation
  ../../../intern/atomic
  ../../../intern/guardedalloc
  ../../../intern/mikktspace
  ../../../intern/mantaflow/extern
)


set(SRC
  intern/source/bake_api.c
  intern/source/external_engine.c
  intern/source/imagetexture.c
  intern/source/initrender.c
  intern/source/multires_bake.c
  intern/source/pipeline.c
  intern/source/pointdensity.c
  intern/source/render_result.c
  intern/source/render_texture.c
  intern/source/zbuf.c

  extern/include/RE_bake.h
  extern/include/RE_engine.h
  extern/include/RE_multires_bake.h
  extern/include/RE_pipeline.h
  extern/include/RE_render_ext.h
  extern/include/RE_shader_ext.h
  intern/include/initrender.h
  intern/include/render_result.h
  intern/include/render_types.h
  intern/include/renderpipeline.h
  intern/include/texture.h
  intern/include/zbuf.h
)

set(LIB
)

if(WITH_PYTHON)
  add_definitions(-DWITH_PYTHON)
  list(APPEND INC
    ../python
  )
endif()

if(WITH_IMAGE_OPENEXR)
  list(APPEND LIB
    bf_imbuf_openexr
  )
  add_definitions(-DWITH_OPENEXR)
endif()

if(WITH_FREESTYLE)
  list(APPEND INC
    ../freestyle
  )
  list(APPEND LIB
    bf_freestyle
  )
  add_definitions(-DWITH_FREESTYLE)
endif()

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()

if(APPLE)
  # SSE math is enabled by default on x86_64
  if(CMAKE_OSX_ARCHITECTURES MATCHES "i386")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mfpmath=sse")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mfpmath=sse")
  endif()
endif()


blender_add_lib_nolist(bf_render "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
