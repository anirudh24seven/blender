set(INC
  ../include
  ../../blenfont
  ../../blenkernel
  ../../blenlib
  ../../blenloader
  ../../blentranslation
  ../../bmesh
  ../../depsgraph
  ../../gpu
  ../../imbuf
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
  area.c
  area_query.c
  area_utils.c
  glutil.c
  screen_context.c
  screen_draw.c
  screen_edit.c
  screen_geometry.c
  screen_ops.c
  screen_user_menu.c
  screendump.c
  workspace_edit.c
  workspace_layout_edit.c

  screen_intern.h
)

set(LIB
  bf_editor_datafiles
  bf_editor_space_sequencer
)

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()

add_definitions(${GL_DEFINITIONS})

blender_add_lib(bf_editor_screen "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
