# Build Draco library.
add_subdirectory(dracoenc)

# Build blender-draco-exporter module.
set(SRC
  src/draco-compressor.cpp
  src/draco-compressor.h
)

set(INC
  dracoenc/src
)

set(LIB
  dracoenc
)

add_library(extern_draco SHARED "${SRC}")
target_include_directories(extern_draco PUBLIC "${INC}")
target_link_libraries(extern_draco PUBLIC "${LIB}")

blender_source_group(extern_draco "${SRC}")
