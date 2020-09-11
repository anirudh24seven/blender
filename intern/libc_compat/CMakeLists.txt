set(INC
  .
)

set(INC_SYS
)

set(SRC
  libc_compat.c
)

set(LIB
)

add_c_flag(-ffast-math)

blender_add_lib(bf_intern_libc_compat "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
