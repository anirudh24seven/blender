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
  ../../nodes
  ../../render/extern/include
  ../../compositor
  ../../windowmanager
  ../../../../intern/glew-mx
  ../../../../intern/guardedalloc
)

set(INC_SYS
  ${GLEW_INCLUDE_PATH}
)

set(SRC
  drawnode.c
  node_add.c
  node_buttons.c
  node_draw.c
  node_edit.c
  node_gizmo.c
  node_group.c
  node_ops.c
  node_relationships.c
  node_select.c
  node_templates.c
  node_toolbar.c
  node_view.c
  space_node.c

  node_intern.h
)

set(LIB
  bf_blenkernel
  bf_blenlib
  bf_editor_screen
)

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()

if(WITH_COMPOSITOR)
  add_definitions(-DWITH_COMPOSITOR)
endif()

if(WITH_OPENIMAGEDENOISE)
  add_definitions(-DWITH_OPENIMAGEDENOISE)
endif()

add_definitions(${GL_DEFINITIONS})

blender_add_lib(bf_editor_space_node "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
