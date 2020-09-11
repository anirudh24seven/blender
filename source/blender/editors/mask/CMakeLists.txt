set(INC
  ../include
  ../../blenkernel
  ../../blenlib
  ../../depsgraph
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
  mask_add.c
  mask_draw.c
  mask_edit.c
  mask_editaction.c
  mask_ops.c
  mask_query.c
  mask_relationships.c
  mask_select.c
  mask_shapekey.c

  mask_intern.h
)

set(LIB
)

add_definitions(${GL_DEFINITIONS})

blender_add_lib(bf_editor_mask "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
