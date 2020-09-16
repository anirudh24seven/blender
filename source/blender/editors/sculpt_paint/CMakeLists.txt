set(INC
  ../include
  ../uvedit
  ../../blenkernel
  ../../blenlib
  ../../blentranslation
  ../../bmesh
  ../../depsgraph
  ../../draw
  ../../gpu
  ../../imbuf
  ../../makesdna
  ../../makesrna
  ../../render/extern/include
  ../../windowmanager
  ../../../../intern/atomic
  ../../../../intern/clog
  ../../../../intern/glew-mx
  ../../../../intern/guardedalloc
)

set(SRC
  paint_cursor.c
  paint_curve.c
  paint_curve_undo.c
  paint_hide.c
  paint_image.c
  paint_image_2d.c
  paint_image_proj.c
  paint_mask.c
  paint_ops.c
  paint_stroke.c
  paint_utils.c
  paint_vertex.c
  paint_vertex_color_ops.c
  paint_vertex_color_utils.c
  paint_vertex_proj.c
  paint_vertex_weight_ops.c
  paint_vertex_weight_utils.c
  sculpt.c
  sculpt_automasking.c
  sculpt_boundary.c
  sculpt_cloth.c
  sculpt_detail.c
  sculpt_dyntopo.c
  sculpt_face_set.c
  sculpt_filter_color.c
  sculpt_filter_mask.c
  sculpt_filter_mesh.c
  sculpt_mask_expand.c
  sculpt_multiplane_scrape.c
  sculpt_paint_color.c
  sculpt_pose.c
  sculpt_smooth.c
  sculpt_transform.c
  sculpt_undo.c
  sculpt_uv.c

  paint_intern.h
  sculpt_intern.h
)

set(LIB
  bf_blenkernel
  bf_blenlib
)

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()


blender_add_lib(bf_editor_sculpt_paint "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
