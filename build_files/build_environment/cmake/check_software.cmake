if(UNIX)
  if(APPLE)
    set(_libtoolize_name glibtoolize)
  else()
    set(_libtoolize_name libtoolize)
  endif()

  set(_required_software
    autoconf
    automake
    ${_libtoolize_name}
    nasm
    yasm
    tclsh
    bison
  )

  foreach(_software ${_required_software})
    find_program(_software_find NAMES ${_software})
    if(NOT _software_find)
      set(_software_missing "${_software_missing}${_software} ")
    endif()
    unset(_software_find CACHE)
  endforeach()

  if(APPLE)
    if(NOT EXISTS "/usr/local/opt/bison/bin/bison")
      set(_software_missing "${_software_missing} bison")
    endif()
  endif()

  if(_software_missing)
    message(
      "\n"
      "Missing software for building Blender dependencies:\n"
      "  ${_software_missing}\n"
      "\n"
      "On Debian and Ubuntu:\n"
      "  apt install autoconf automake libtool yasm nasm tcl\n"
      "\n"
      "On macOS (with homebrew):\n"
      "  brew install cmake autoconf automake libtool yasm nasm bison\n"
      "\n"
      "Other platforms:\n"
      "  Install equivalent packages.\n")
    message(FATAL_ERROR "Install missing software before continuing")
  endif()
endif()
