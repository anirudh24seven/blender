set(INC
  ../include
  ../../blenkernel
  ../../blenlib
  ../../blentranslation
  ../../depsgraph
  ../../makesdna
  ../../makesrna
  ../../windowmanager
)

set(INC_SYS

)

set(SRC
  scene_edit.c
)

set(LIB
  bf_blenkernel
  bf_blenlib
)

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()

blender_add_lib(bf_editor_scene "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
