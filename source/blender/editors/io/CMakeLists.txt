set(INC
  ../include
  ../../blenkernel
  ../../blenlib
  ../../blentranslation
  ../../bmesh
  ../../depsgraph
  ../../io/alembic
  ../../io/collada
  ../../io/usd
  ../../makesdna
  ../../makesrna
  ../../windowmanager
  ../../../../intern/guardedalloc
)

set(INC_SYS

)

set(SRC
  io_alembic.c
  io_cache.c
  io_collada.c
  io_ops.c
  io_usd.c

  io_alembic.h
  io_cache.h
  io_collada.h
  io_ops.h
  io_usd.h
)

set(LIB
  bf_blenkernel
  bf_blenlib
)

if(WITH_OPENCOLLADA)
  list(APPEND LIB
    bf_collada
  )
  add_definitions(-DWITH_COLLADA)
endif()

if(WITH_ALEMBIC)
  list(APPEND LIB
    bf_alembic
  )
  add_definitions(-DWITH_ALEMBIC)
endif()

if(WITH_USD)
  list(APPEND LIB
    bf_usd
  )
  add_definitions(-DWITH_USD)
endif()

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()

blender_add_lib(bf_editor_io "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
