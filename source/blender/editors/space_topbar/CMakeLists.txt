set(INC
  ../include
  ../../blenkernel
  ../../blenlib
  ../../blenloader
  ../../blentranslation
  ../../gpu
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
  space_topbar.c
)

set(LIB
)

add_definitions(${GL_DEFINITIONS})

blender_add_lib(bf_editor_space_topbar "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
