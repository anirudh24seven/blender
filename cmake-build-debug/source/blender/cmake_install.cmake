# Install script for directory: /Users/anirudh/workspace/blender-git/blender/source/blender

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/${BUILD_TYPE}")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/datatoc/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/windowmanager/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/blenkernel/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/blenlib/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/bmesh/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/draw/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/render/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/blenfont/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/blentranslation/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/blenloader/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/depsgraph/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/ikplugin/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/simulation/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/gpu/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/imbuf/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/nodes/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/modifiers/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/gpencil_modifiers/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/shader_fx/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/io/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/functions/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/makesdna/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/makesrna/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/compositor/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/imbuf/intern/openexr/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/imbuf/intern/oiio/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/imbuf/intern/dds/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/imbuf/intern/cineon/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/python/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/freestyle/cmake_install.cmake")

endif()

