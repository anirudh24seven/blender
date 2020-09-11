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

set(INC_SYS
  ${GLEW_INCLUDE_PATH}
)

set(SRC
  action_buttons.c
  action_data.c
  action_draw.c
  action_edit.c
  action_ops.c
  action_select.c
  space_action.c

  action_intern.h
)

set(LIB
  bf_blenkernel
  bf_blenlib
)

add_definitions(${GL_DEFINITIONS})

blender_add_lib(bf_editor_space_action "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
