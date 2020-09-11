set(INC
  ../include
  ../../blenkernel
  ../../blenlib
  ../../depsgraph
  ../../makesdna
  ../../makesrna
  ../../windowmanager
)

set(INC_SYS
)

set(SRC
  geometry_attributes.c
  geometry_ops.c

  geometry_intern.h
)

set(LIB
  bf_blenkernel
  bf_depsgraph
  bf_editor_object
  bf_windowmanager
)

blender_add_lib(bf_editor_geometry "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
