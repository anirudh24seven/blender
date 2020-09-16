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
  ../../../../extern/curve_fit_nd
)

set(SRC
  curve_ops.c
  editcurve.c
  editcurve_add.c
  editcurve_paint.c
  editcurve_query.c
  editcurve_select.c
  editcurve_undo.c
  editfont.c
  editfont_undo.c

  curve_intern.h
)

set(LIB
  bf_blenkernel
  bf_blenlib
  extern_curve_fit_nd
)

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()


blender_add_lib(bf_editor_curve "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
