set(INC
  ../include
  ../space_sequencer
  ../../blenkernel
  ../../blenlib
  ../../blentranslation
  ../../bmesh
  ../../depsgraph
  ../../gpu
  ../../imbuf
  ../../makesdna
  ../../makesrna
  ../../windowmanager
  ../../../../intern/clog
  ../../../../intern/glew-mx
  ../../../../intern/guardedalloc
)

set(INC_SYS
  ${GLEW_INCLUDE_PATH}
)

set(SRC
  ed_transverts.c
  ed_util.c
  ed_util_imbuf.c
  gizmo_utils.c
  numinput.c
  select_utils.c

  # general includes
  ../include/BIF_glutil.h
  ../include/ED_anim_api.h
  ../include/ED_armature.h
  ../include/ED_buttons.h
  ../include/ED_clip.h
  ../include/ED_curve.h
  ../include/ED_datafiles.h
  ../include/ED_fileselect.h
  ../include/ED_gizmo_library.h
  ../include/ED_gizmo_utils.h
  ../include/ED_gpencil.h
  ../include/ED_image.h
  ../include/ED_info.h
  ../include/ED_keyframes_draw.h
  ../include/ED_keyframes_edit.h
  ../include/ED_keyframing.h
  ../include/ED_lattice.h
  ../include/ED_markers.h
  ../include/ED_mask.h
  ../include/ED_mball.h
  ../include/ED_mesh.h
  ../include/ED_node.h
  ../include/ED_numinput.h
  ../include/ED_object.h
  ../include/ED_outliner.h
  ../include/ED_paint.h
  ../include/ED_particle.h
  ../include/ED_physics.h
  ../include/ED_render.h
  ../include/ED_scene.h
  ../include/ED_screen.h
  ../include/ED_screen_types.h
  ../include/ED_sculpt.h
  ../include/ED_select_utils.h
  ../include/ED_sequencer.h
  ../include/ED_sound.h
  ../include/ED_space_api.h
  ../include/ED_text.h
  ../include/ED_time_scrub_ui.h
  ../include/ED_transform.h
  ../include/ED_transform_snap_object_context.h
  ../include/ED_transverts.h
  ../include/ED_types.h
  ../include/ED_undo.h
  ../include/ED_userpref.h
  ../include/ED_util.h
  ../include/ED_util_imbuf.h
  ../include/ED_uvedit.h
  ../include/ED_view3d.h
  ../include/ED_view3d_offscreen.h
  ../include/UI_icons.h
  ../include/UI_interface.h
  ../include/UI_interface_icons.h
  ../include/UI_resources.h
  ../include/UI_view2d.h
)

set(LIB
)

add_definitions(${GL_DEFINITIONS})

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()

if(WITH_PYTHON)
  add_definitions(-DWITH_PYTHON)
  list(APPEND INC
    ../../python
  )
endif()

blender_add_lib(bf_editor_util "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
