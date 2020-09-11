set(INC
  ../include
  ../../blenkernel
  ../../blenlib
  ../../depsgraph
  ../../makesdna
  ../../makesrna
  ../../render/extern/include
  ../../windowmanager
  ../../../../intern/clog
  ../../../../intern/guardedalloc
)

set(INC_SYS

)

set(SRC
  editlattice_select.c
  editlattice_tools.c
  editlattice_undo.c
  lattice_ops.c

  lattice_intern.h
)

set(LIB
)

blender_add_lib(bf_editor_lattice "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
