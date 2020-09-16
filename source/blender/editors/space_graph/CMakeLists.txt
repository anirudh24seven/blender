set(INC
  ../include
  ../../blenkernel
  ../../blenlib
  ../../blentranslation
  ../../depsgraph
  ../../gpu
  ../../makesdna
  ../../makesrna
  ../../windowmanager
  ../../../../intern/glew-mx
  ../../../../intern/guardedalloc
)

set(SRC
  graph_buttons.c
  graph_draw.c
  graph_edit.c
  graph_ops.c
  graph_select.c
  graph_utils.c
  space_graph.c

  graph_intern.h
)

set(LIB
  bf_blenkernel
  bf_blenlib
)

if(WITH_AUDASPACE)
  list(APPEND INC_SYS
    ${AUDASPACE_C_INCLUDE_DIRS}
  )
  list(APPEND LIB
    bf_intern_audaspace

    ${AUDASPACE_C_LIBRARIES}
    ${AUDASPACE_PY_LIBRARIES}
  )
  add_definitions(-DWITH_AUDASPACE)
endif()

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()


blender_add_lib(bf_editor_space_graph "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
