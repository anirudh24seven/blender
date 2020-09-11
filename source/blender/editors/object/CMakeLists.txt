set(INC
  ../include
  ../../blenfont
  ../../blenkernel
  ../../blenlib
  ../../blentranslation
  ../../bmesh
  ../../depsgraph
  ../../gpencil_modifiers
  ../../gpu
  ../../ikplugin
  ../../imbuf
  ../../makesdna
  ../../makesrna
  ../../modifiers
  ../../python
  ../../shader_fx
  ../../render/extern/include
  ../../windowmanager
  ../../../../intern/clog
  ../../../../intern/glew-mx
  ../../../../intern/guardedalloc
)

set(INC_SYS
  ${GLEW_INCLUDE_PATH}
)

set(SRC
  object_add.c
  object_bake.c
  object_bake_api.c
  object_collection.c
  object_constraint.c
  object_data_transfer.c
  object_data_transform.c
  object_edit.c
  object_facemap_ops.c
  object_gpencil_modifier.c
  object_hook.c
  object_modes.c
  object_modifier.c
  object_ops.c
  object_random.c
  object_relations.c
  object_remesh.c
  object_select.c
  object_shader_fx.c
  object_shapekey.c
  object_transform.c
  object_utils.c
  object_vgroup.c
  object_volume.c
  object_warp.c

  object_intern.h
)

set(LIB
  bf_blenkernel
  bf_blenlib
  bf_editor_mesh
  bf_render
  bf_windowmanager
)

add_definitions(${GL_DEFINITIONS})

if(WITH_PYTHON)
  add_definitions(-DWITH_PYTHON)
endif()

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()

blender_add_lib(bf_editor_object "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
