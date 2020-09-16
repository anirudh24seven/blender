set(INC
  ../include
  ../../blenkernel
  ../../blenlib
  ../../blenloader
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
  ../../../../intern/glew-mx
  ../../../../intern/guardedalloc
)

set(SRC
  render_internal.c
  render_opengl.c
  render_ops.c
  render_preview.c
  render_shading.c
  render_update.c
  render_view.c

  render_intern.h
)

set(LIB
)

if(WITH_HEADLESS)
  add_definitions(-DWITH_HEADLESS)
else()
  list(APPEND LIB
    bf_editor_datafiles
  )
endif()


if(WITH_FREESTYLE)
  list(APPEND INC
    ../../freestyle
  )
  add_definitions(-DWITH_FREESTYLE)
endif()

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()

blender_add_lib(bf_editor_render "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
