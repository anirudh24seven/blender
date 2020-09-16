set(INC
  ../include
  ../../blenfont
  ../../blenkernel
  ../../blenlib
  ../../blenloader
  ../../blentranslation
  ../../gpu
  ../../imbuf
  ../../makesdna
  ../../makesrna
  ../../render/extern/include
  ../../windowmanager
  ../../../../intern/atomic
  ../../../../intern/glew-mx
  ../../../../intern/guardedalloc
)

set(SRC
  file_draw.c
  file_ops.c
  file_panels.c
  file_utils.c
  filelist.c
  filesel.c
  fsmenu.c
  space_file.c

  file_intern.h
  filelist.h
  fsmenu.h
)

set(LIB
)

if(WITH_HEADLESS)
  add_definitions(-DWITH_HEADLESS)
else()
  list(APPEND LIB
    bf_editor_datafiles
  )
endif()

if(WITH_IMAGE_OPENEXR)
  add_definitions(-DWITH_OPENEXR)
endif()

if(WITH_OPENIMAGEIO)
  add_definitions(-DWITH_OPENIMAGEIO)
endif()

if(WITH_IMAGE_TIFF)
  add_definitions(-DWITH_TIFF)
endif()

if(WITH_IMAGE_OPENJPEG)
  add_definitions(-DWITH_OPENJPEG)
endif()

if(WITH_IMAGE_DDS)
  add_definitions(-DWITH_DDS)
endif()

if(WITH_IMAGE_CINEON)
  add_definitions(-DWITH_CINEON)
endif()

if(WITH_IMAGE_HDR)
  add_definitions(-DWITH_HDR)
endif()

if(WITH_INTERNATIONAL)
  add_definitions(-DWITH_INTERNATIONAL)
endif()


if(WITH_FREESTYLE)
  add_definitions(-DWITH_FREESTYLE)
endif()

blender_add_lib(bf_editor_space_file "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
