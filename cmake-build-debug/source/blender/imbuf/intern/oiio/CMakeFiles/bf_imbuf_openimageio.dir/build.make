# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/anirudh/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/anirudh/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/anirudh/workspace/blender-git/blender

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anirudh/workspace/blender-git/blender/cmake-build-debug

# Include any dependencies generated for this target.
include source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/depend.make

# Include the progress variables for this target.
include source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/progress.make

# Include the compile flags for this target's objects.
include source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/flags.make

source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/openimageio_api.cpp.o: source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/flags.make
source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/openimageio_api.cpp.o: ../source/blender/imbuf/intern/oiio/openimageio_api.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/openimageio_api.cpp.o"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/imbuf/intern/oiio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bf_imbuf_openimageio.dir/openimageio_api.cpp.o -c /Users/anirudh/workspace/blender-git/blender/source/blender/imbuf/intern/oiio/openimageio_api.cpp

source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/openimageio_api.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bf_imbuf_openimageio.dir/openimageio_api.cpp.i"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/imbuf/intern/oiio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anirudh/workspace/blender-git/blender/source/blender/imbuf/intern/oiio/openimageio_api.cpp > CMakeFiles/bf_imbuf_openimageio.dir/openimageio_api.cpp.i

source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/openimageio_api.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bf_imbuf_openimageio.dir/openimageio_api.cpp.s"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/imbuf/intern/oiio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anirudh/workspace/blender-git/blender/source/blender/imbuf/intern/oiio/openimageio_api.cpp -o CMakeFiles/bf_imbuf_openimageio.dir/openimageio_api.cpp.s

# Object files for target bf_imbuf_openimageio
bf_imbuf_openimageio_OBJECTS = \
"CMakeFiles/bf_imbuf_openimageio.dir/openimageio_api.cpp.o"

# External object files for target bf_imbuf_openimageio
bf_imbuf_openimageio_EXTERNAL_OBJECTS =

lib/libbf_imbuf_openimageio.a: source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/openimageio_api.cpp.o
lib/libbf_imbuf_openimageio.a: source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/build.make
lib/libbf_imbuf_openimageio.a: source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../../../lib/libbf_imbuf_openimageio.a"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/imbuf/intern/oiio && $(CMAKE_COMMAND) -P CMakeFiles/bf_imbuf_openimageio.dir/cmake_clean_target.cmake
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/imbuf/intern/oiio && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bf_imbuf_openimageio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/build: lib/libbf_imbuf_openimageio.a

.PHONY : source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/build

source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/clean:
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/imbuf/intern/oiio && $(CMAKE_COMMAND) -P CMakeFiles/bf_imbuf_openimageio.dir/cmake_clean.cmake
.PHONY : source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/clean

source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/depend:
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anirudh/workspace/blender-git/blender /Users/anirudh/workspace/blender-git/blender/source/blender/imbuf/intern/oiio /Users/anirudh/workspace/blender-git/blender/cmake-build-debug /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/imbuf/intern/oiio /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/blender/imbuf/intern/oiio/CMakeFiles/bf_imbuf_openimageio.dir/depend

