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
include source/blender/editors/util/CMakeFiles/bf_editor_util.dir/depend.make

# Include the progress variables for this target.
include source/blender/editors/util/CMakeFiles/bf_editor_util.dir/progress.make

# Include the compile flags for this target's objects.
include source/blender/editors/util/CMakeFiles/bf_editor_util.dir/flags.make

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_transverts.c.o: source/blender/editors/util/CMakeFiles/bf_editor_util.dir/flags.make
source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_transverts.c.o: ../source/blender/editors/util/ed_transverts.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_transverts.c.o"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bf_editor_util.dir/ed_transverts.c.o   -c /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/ed_transverts.c

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_transverts.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bf_editor_util.dir/ed_transverts.c.i"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/ed_transverts.c > CMakeFiles/bf_editor_util.dir/ed_transverts.c.i

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_transverts.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bf_editor_util.dir/ed_transverts.c.s"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/ed_transverts.c -o CMakeFiles/bf_editor_util.dir/ed_transverts.c.s

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_util.c.o: source/blender/editors/util/CMakeFiles/bf_editor_util.dir/flags.make
source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_util.c.o: ../source/blender/editors/util/ed_util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_util.c.o"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bf_editor_util.dir/ed_util.c.o   -c /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/ed_util.c

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bf_editor_util.dir/ed_util.c.i"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/ed_util.c > CMakeFiles/bf_editor_util.dir/ed_util.c.i

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bf_editor_util.dir/ed_util.c.s"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/ed_util.c -o CMakeFiles/bf_editor_util.dir/ed_util.c.s

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_util_imbuf.c.o: source/blender/editors/util/CMakeFiles/bf_editor_util.dir/flags.make
source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_util_imbuf.c.o: ../source/blender/editors/util/ed_util_imbuf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_util_imbuf.c.o"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bf_editor_util.dir/ed_util_imbuf.c.o   -c /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/ed_util_imbuf.c

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_util_imbuf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bf_editor_util.dir/ed_util_imbuf.c.i"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/ed_util_imbuf.c > CMakeFiles/bf_editor_util.dir/ed_util_imbuf.c.i

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_util_imbuf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bf_editor_util.dir/ed_util_imbuf.c.s"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/ed_util_imbuf.c -o CMakeFiles/bf_editor_util.dir/ed_util_imbuf.c.s

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/gizmo_utils.c.o: source/blender/editors/util/CMakeFiles/bf_editor_util.dir/flags.make
source/blender/editors/util/CMakeFiles/bf_editor_util.dir/gizmo_utils.c.o: ../source/blender/editors/util/gizmo_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object source/blender/editors/util/CMakeFiles/bf_editor_util.dir/gizmo_utils.c.o"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bf_editor_util.dir/gizmo_utils.c.o   -c /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/gizmo_utils.c

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/gizmo_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bf_editor_util.dir/gizmo_utils.c.i"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/gizmo_utils.c > CMakeFiles/bf_editor_util.dir/gizmo_utils.c.i

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/gizmo_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bf_editor_util.dir/gizmo_utils.c.s"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/gizmo_utils.c -o CMakeFiles/bf_editor_util.dir/gizmo_utils.c.s

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/numinput.c.o: source/blender/editors/util/CMakeFiles/bf_editor_util.dir/flags.make
source/blender/editors/util/CMakeFiles/bf_editor_util.dir/numinput.c.o: ../source/blender/editors/util/numinput.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object source/blender/editors/util/CMakeFiles/bf_editor_util.dir/numinput.c.o"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bf_editor_util.dir/numinput.c.o   -c /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/numinput.c

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/numinput.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bf_editor_util.dir/numinput.c.i"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/numinput.c > CMakeFiles/bf_editor_util.dir/numinput.c.i

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/numinput.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bf_editor_util.dir/numinput.c.s"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/numinput.c -o CMakeFiles/bf_editor_util.dir/numinput.c.s

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/select_utils.c.o: source/blender/editors/util/CMakeFiles/bf_editor_util.dir/flags.make
source/blender/editors/util/CMakeFiles/bf_editor_util.dir/select_utils.c.o: ../source/blender/editors/util/select_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object source/blender/editors/util/CMakeFiles/bf_editor_util.dir/select_utils.c.o"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bf_editor_util.dir/select_utils.c.o   -c /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/select_utils.c

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/select_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bf_editor_util.dir/select_utils.c.i"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/select_utils.c > CMakeFiles/bf_editor_util.dir/select_utils.c.i

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/select_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bf_editor_util.dir/select_utils.c.s"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util/select_utils.c -o CMakeFiles/bf_editor_util.dir/select_utils.c.s

# Object files for target bf_editor_util
bf_editor_util_OBJECTS = \
"CMakeFiles/bf_editor_util.dir/ed_transverts.c.o" \
"CMakeFiles/bf_editor_util.dir/ed_util.c.o" \
"CMakeFiles/bf_editor_util.dir/ed_util_imbuf.c.o" \
"CMakeFiles/bf_editor_util.dir/gizmo_utils.c.o" \
"CMakeFiles/bf_editor_util.dir/numinput.c.o" \
"CMakeFiles/bf_editor_util.dir/select_utils.c.o"

# External object files for target bf_editor_util
bf_editor_util_EXTERNAL_OBJECTS =

lib/libbf_editor_util.a: source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_transverts.c.o
lib/libbf_editor_util.a: source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_util.c.o
lib/libbf_editor_util.a: source/blender/editors/util/CMakeFiles/bf_editor_util.dir/ed_util_imbuf.c.o
lib/libbf_editor_util.a: source/blender/editors/util/CMakeFiles/bf_editor_util.dir/gizmo_utils.c.o
lib/libbf_editor_util.a: source/blender/editors/util/CMakeFiles/bf_editor_util.dir/numinput.c.o
lib/libbf_editor_util.a: source/blender/editors/util/CMakeFiles/bf_editor_util.dir/select_utils.c.o
lib/libbf_editor_util.a: source/blender/editors/util/CMakeFiles/bf_editor_util.dir/build.make
lib/libbf_editor_util.a: source/blender/editors/util/CMakeFiles/bf_editor_util.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C static library ../../../../lib/libbf_editor_util.a"
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && $(CMAKE_COMMAND) -P CMakeFiles/bf_editor_util.dir/cmake_clean_target.cmake
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bf_editor_util.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/blender/editors/util/CMakeFiles/bf_editor_util.dir/build: lib/libbf_editor_util.a

.PHONY : source/blender/editors/util/CMakeFiles/bf_editor_util.dir/build

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/clean:
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util && $(CMAKE_COMMAND) -P CMakeFiles/bf_editor_util.dir/cmake_clean.cmake
.PHONY : source/blender/editors/util/CMakeFiles/bf_editor_util.dir/clean

source/blender/editors/util/CMakeFiles/bf_editor_util.dir/depend:
	cd /Users/anirudh/workspace/blender-git/blender/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anirudh/workspace/blender-git/blender /Users/anirudh/workspace/blender-git/blender/source/blender/editors/util /Users/anirudh/workspace/blender-git/blender/cmake-build-debug /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/source/blender/editors/util/CMakeFiles/bf_editor_util.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/blender/editors/util/CMakeFiles/bf_editor_util.dir/depend

