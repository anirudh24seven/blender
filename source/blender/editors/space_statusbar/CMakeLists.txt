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
  space_statusbar.c
)

set(LIB
  bf_blenkernel
  bf_blenlib
)

add_definitions(${GL_DEFINITIONS})

blender_add_lib(bf_editor_space_statusbar "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
