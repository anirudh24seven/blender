set(INC
  ../include
  ../../blenkernel
  ../../blenlib
  ../../blentranslation
  ../../depsgraph
  ../../gpu
  ../../imbuf
  ../../makesdna
  ../../makesrna
  ../../windowmanager
  ../../../../intern/glew-mx
  ../../../../intern/guardedalloc
)


set(SRC
  outliner_collections.c
  outliner_dragdrop.c
  outliner_draw.c
  outliner_edit.c
  outliner_ops.c
  outliner_select.c
  outliner_sync.c
  outliner_tools.c
  outliner_tree.c
  outliner_utils.c
  space_outliner.c

  outliner_intern.h
)

set(LIB
  bf_blenkernel
  bf_blenlib
  bf_editor_undo
)

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()


blender_add_lib(bf_editor_space_outliner "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
