# Install script for directory: /Users/anirudh/workspace/blender-git/blender/intern

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
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/clog/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/ghost/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/guardedalloc/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/libmv/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/memutil/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/numaapi/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/opencolorio/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/opensubdiv/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/mikktspace/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/glew-mx/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/eigen/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/sky/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/audaspace/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/dualcon/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/iksolver/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/itasc/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/cycles/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/locale/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/rigidbody/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/mantaflow/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/openvdb/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/quadriflow/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/intern/ffmpeg/cmake_install.cmake")

endif()

