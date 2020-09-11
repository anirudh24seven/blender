# -----------------------------------------------------------------------------
# Build msgfmt executable

blender_include_dirs(
  ../../../../intern/guardedalloc
  ../../blenlib
)

set(SRC
  msgfmt.c
)

setup_libdirs()
add_cc_flags_custom_test(msgfmt)

if(APPLE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${PLATFORM_LINKFLAGS}")
endif()

if(WIN32)
  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /nodefaultlib:MSVCRT.lib")
endif()

add_executable(msgfmt ${SRC})

target_link_libraries(msgfmt bf_blenlib)
target_link_libraries(msgfmt bf_intern_guardedalloc)

if(WIN32)
  target_link_libraries(msgfmt bf_intern_utfconv)
endif()

target_link_libraries(msgfmt ${ZLIB_LIBRARIES})
target_link_libraries(msgfmt ${PLATFORM_LINKLIBS})
