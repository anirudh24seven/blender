set(INC
  .
  include
)

set(INC_SYS

)

set(SRC
  include/sdlew.h
  src/sdlew.c
)

set(LIB
)

blender_add_lib(extern_sdlew "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
