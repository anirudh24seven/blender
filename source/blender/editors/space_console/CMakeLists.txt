set(INC
  ../include
  ../../blenfont
  ../../blenkernel
  ../../blenlib
  ../../gpu
  ../../makesdna
  ../../makesrna
  ../../windowmanager
  ../../../../intern/glew-mx
  ../../../../intern/guardedalloc
)

set(INC_SYS
  ${GLEW_INCLUDE_PATH}
)

set(SRC
  console_draw.c
  console_ops.c
  space_console.c

  console_intern.h
)

set(LIB
  bf_blenkernel
  bf_blenlib
)

if(WITH_PYTHON)
  add_definitions(-DWITH_PYTHON)
endif()

add_definitions(${GL_DEFINITIONS})

blender_add_lib(bf_editor_space_console "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
