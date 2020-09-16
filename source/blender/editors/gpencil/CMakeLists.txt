set(INC
  ../include
  ../../blenfont
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
  annotate_draw.c
  annotate_paint.c
  drawgpencil.c
  editaction_gpencil.c
  gpencil_add_monkey.c
  gpencil_add_stroke.c
  gpencil_armature.c
  gpencil_convert.c
  gpencil_data.c
  gpencil_edit.c
  gpencil_fill.c
  gpencil_interpolate.c
  gpencil_merge.c
  gpencil_mesh.c
  gpencil_ops.c
  gpencil_ops_versioning.c
  gpencil_paint.c
  gpencil_primitive.c
  gpencil_sculpt_paint.c
  gpencil_select.c
  gpencil_undo.c
  gpencil_utils.c
  gpencil_uv.c
  gpencil_vertex_ops.c
  gpencil_vertex_paint.c
  gpencil_weight_paint.c

  gpencil_intern.h
)

set(LIB
  bf_blenkernel
  bf_blenlib
)

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()


blender_add_lib(bf_editor_gpencil "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
