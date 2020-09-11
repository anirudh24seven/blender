set(INC
  include
)

set(INC_SYS

)

set(SRC
  source/numaapi.c
  source/numaapi_linux.c
  source/numaapi_stub.c
  source/numaapi_win32.c

  include/numaapi.h
  source/build_config.h
)

set(LIB
)

add_definitions(-DWITH_DYNLOAD)

blender_add_lib(bf_intern_numaapi "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
