set(INC
  .
  intern
  ../blenfont
  ../blenkernel
  ../blenlib
  ../blentranslation
  ../bmesh
  ../depsgraph
  ../editors/include
  ../makesdna
  ../makesrna
  ../render/extern/include
  ../windowmanager
  ../../../intern/eigen
  ../../../intern/guardedalloc
)

set(INC_SYS
  ${ZLIB_INCLUDE_DIRS}
)

set(SRC
  intern/MOD_gpencil_ui_common.c

  intern/MOD_gpencil_util.c
  intern/MOD_gpencilarmature.c
  intern/MOD_gpencilarray.c
  intern/MOD_gpencilbuild.c
  intern/MOD_gpencilcolor.c
  intern/MOD_gpencilhook.c
  intern/MOD_gpencillattice.c
  intern/MOD_gpencilmirror.c
  intern/MOD_gpencilmultiply.c
  intern/MOD_gpencilnoise.c
  intern/MOD_gpenciloffset.c
  intern/MOD_gpencilopacity.c
  intern/MOD_gpencilsimplify.c
  intern/MOD_gpencilsmooth.c
  intern/MOD_gpencilsubdiv.c
  intern/MOD_gpenciltexture.c
  intern/MOD_gpencilthick.c
  intern/MOD_gpenciltime.c
  intern/MOD_gpenciltint.c

  MOD_gpencil_modifiertypes.h
  intern/MOD_gpencil_ui_common.h
  intern/MOD_gpencil_util.h
)

set(LIB
)

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()


blender_add_lib(bf_gpencil_modifiers "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
