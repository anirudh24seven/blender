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

set(INC_SYS
  ${GLEW_INCLUDE_PATH}
)

set(SRC
  nla_buttons.c
  nla_channels.c
  nla_draw.c
  nla_edit.c
  nla_ops.c
  nla_select.c
  space_nla.c

  nla_intern.h
)

set(LIB
  bf_blenkernel
  bf_blenlib
)

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()

add_definitions(${GL_DEFINITIONS})

blender_add_lib(bf_editor_space_nla "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
