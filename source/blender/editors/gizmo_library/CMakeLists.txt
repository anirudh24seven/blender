set(INC
  ../include
  ../../blenkernel
  ../../blenlib
  ../../blentranslation
  ../../bmesh
  ../../depsgraph
  ../../gpu
  ../../makesdna
  ../../makesrna
  ../../windowmanager
  ../../../../intern/eigen
  ../../../../intern/glew-mx
  ../../../../intern/guardedalloc
)

set(INC_SYS
  ${GLEW_INCLUDE_PATH}
)

set(SRC
  gizmo_draw_utils.c
  gizmo_geometry.h
  gizmo_library_intern.h
  gizmo_library_presets.c
  gizmo_library_utils.c
  geometry/geom_arrow_gizmo.c
  geometry/geom_cube_gizmo.c
  geometry/geom_dial_gizmo.c
  gizmo_types/arrow3d_gizmo.c
  gizmo_types/blank3d_gizmo.c
  gizmo_types/button2d_gizmo.c
  gizmo_types/cage2d_gizmo.c
  gizmo_types/cage3d_gizmo.c
  gizmo_types/dial3d_gizmo.c
  gizmo_types/move3d_gizmo.c
  gizmo_types/primitive3d_gizmo.c
  gizmo_types/snap3d_gizmo.c
)

set(LIB
)

add_definitions(${GL_DEFINITIONS})

blender_add_lib(bf_editor_gizmo_library "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
