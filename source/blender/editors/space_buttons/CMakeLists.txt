set(INC
  ../include
  ../../blenkernel
  ../../blenlib
  ../../blentranslation
  ../../gpu
  ../../makesdna
  ../../makesrna
  ../../windowmanager
  ../../../../intern/glew-mx
  ../../../../intern/guardedalloc
)

set(SRC
  buttons_context.c
  buttons_ops.c
  buttons_texture.c
  space_buttons.c

  buttons_intern.h
)

set(LIB
)

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()


if(WITH_FREESTYLE)
  add_definitions(-DWITH_FREESTYLE)
endif()

if(WITH_EXPERIMENTAL_FEATURES)
  add_definitions(-DWITH_PARTICLE_NODES)
  add_definitions(-DWITH_HAIR_NODES)
endif()

blender_add_lib(bf_editor_space_buttons "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
