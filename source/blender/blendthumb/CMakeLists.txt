#-----------------------------------------------------------------------------
include_directories(${ZLIB_INCLUDE_DIRS})

set(SRC
  src/BlenderThumb.cpp
  src/BlendThumb.def
  src/BlendThumb.rc
  src/Dll.cpp
)

set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} /nodefaultlib:MSVCRT.lib")

add_library(BlendThumb SHARED ${SRC})
target_link_libraries(BlendThumb ${ZLIB_LIBRARIES})

install(
  FILES $<TARGET_FILE:BlendThumb>
  COMPONENT Blender
  DESTINATION "."
)
