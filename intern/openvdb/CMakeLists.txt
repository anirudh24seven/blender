set(INC
  .
  intern
  ../guardedalloc
)

set(INC_SYS
)

set(SRC
  openvdb_capi.h
)

set(LIB
)

if(WITH_OPENVDB)
  add_definitions(-DWITH_OPENVDB ${OPENVDB_DEFINITIONS})

  list(APPEND INC_SYS
    ${OPENVDB_INCLUDE_DIRS}
  )

  list(APPEND SRC
    intern/openvdb_dense_convert.cc
    intern/openvdb_reader.cc
    intern/openvdb_writer.cc
    intern/openvdb_level_set.cc
    intern/openvdb_transform.cc
    openvdb_capi.cc
    openvdb_util.cc

    intern/openvdb_dense_convert.h
    intern/openvdb_reader.h
    intern/openvdb_writer.h
    intern/openvdb_level_set.h
    intern/openvdb_transform.h
    openvdb_util.h
  )

  list(APPEND LIB
    ${OPENVDB_LIBRARIES}
  )
endif()

blender_add_lib(bf_intern_openvdb "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
