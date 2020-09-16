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
  ../../../../intern/atomic
  ../../../../intern/glew-mx
  ../../../../intern/guardedalloc
)


set(SRC
  sequencer_add.c
  sequencer_buttons.c
  sequencer_draw.c
  sequencer_edit.c
  sequencer_modifier.c
  sequencer_ops.c
  sequencer_preview.c
  sequencer_scopes.c
  sequencer_select.c
  sequencer_view.c
  space_sequencer.c

  sequencer_intern.h
)

set(LIB
  bf_editor_interface
  bf_editor_util
)

if(WITH_AUDASPACE)
  add_definitions(-DWITH_AUDASPACE)

  list(APPEND INC_SYS
    ${AUDASPACE_C_INCLUDE_DIRS}
  )
  list(APPEND LIB
    ${AUDASPACE_C_LIBRARIES}
    ${AUDASPACE_PY_LIBRARIES}
  )
endif()

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()


blender_add_lib(bf_editor_space_sequencer "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
