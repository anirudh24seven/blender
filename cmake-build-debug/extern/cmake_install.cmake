# Install script for directory: /Users/anirudh/workspace/blender-git/blender/extern

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
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/curve_fit_nd/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/rangetree/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/wcwidth/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/bullet2/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/draco/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/glew/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/lzo/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/lzma/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/clew/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/cuew/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/ceres/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/gflags/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/glog/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/audaspace/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/quadriflow/cmake_install.cmake")
  include("/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/extern/mantaflow/cmake_install.cmake")

endif()

