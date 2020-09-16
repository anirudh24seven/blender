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
  ../../../../intern/clog
  ../../../../intern/glew-mx
  ../../../../intern/guardedalloc
)


set(SRC
  anim_channels_defines.c
  anim_channels_edit.c
  anim_deps.c
  anim_draw.c
  anim_filter.c
  anim_ipo_utils.c
  anim_markers.c
  anim_motion_paths.c
  anim_ops.c
  drivers.c
  fmodifier_ui.c
  keyframes_draw.c
  keyframes_edit.c
  keyframes_general.c
  keyframing.c
  keyingsets.c
  time_scrub_ui.c

  anim_intern.h
)

set(LIB
  bf_blenkernel
  bf_blenlib
)

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()

if(WITH_PYTHON)
  add_definitions(-DWITH_PYTHON)
endif()


blender_add_lib(bf_editor_animation "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
