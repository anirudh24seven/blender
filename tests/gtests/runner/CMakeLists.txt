# Build the test runner. This runner takes care of running all GTests, i.e.
# the code that was built using the blender_add_test_lib() CMake macro (see
# macros.cmake).
set(SRC
  blender_test.cc
)

if(WITH_BUILDINFO)
  list(APPEND SRC
    "$<TARGET_OBJECTS:buildinfoobj>"
  )
endif()


# Test libraries need to be linked "whole archive", because they're not
# directly referenced from other code.
get_property(_test_libs GLOBAL PROPERTY BLENDER_TEST_LIBS)
if(WIN32 OR APPLE)
  # Windows and macOS set target_link_options after target creation.
elseif(UNIX)
  list(APPEND TEST_LIBS "-Wl,--whole-archive" ${_test_libs} "-Wl,--no-whole-archive")
else()
  message(FATAL_ERROR "Unknown how to link whole-archive with your compiler ${CMAKE_CXX_COMPILER_ID}")
endif()

# This builds `bin/tests/blender_test`, but does not add it as a single test.
setup_libdirs()
BLENDER_SRC_GTEST_EX(
  NAME blender
  SRC "${SRC}"
  EXTRA_LIBS "${TEST_LIBS}"
  SKIP_ADD_TEST
)
setup_liblinks(blender_test)

if(WIN32)
  foreach(_lib ${_test_libs})
    # Both target_link_libraries and target_link_options are required here
    # target_link_libraries will add any dependend libraries, while just setting
    # the wholearchive flag in target link options will not.
    target_link_libraries(blender_test ${_lib})
    target_link_options(blender_test PRIVATE /wholearchive:$<TARGET_FILE:${_lib}>)
  endforeach()
elseif(APPLE)
  foreach(_lib ${_test_libs})
    # We need -force_load for every test library and target_link_libraries will
    # deduplicate it. So explicitly set as linker option for every test lib.
    target_link_libraries(blender_test ${_lib})
    target_link_options(blender_test PRIVATE "LINKER:-force_load,$<TARGET_FILE:${_lib}>")
  endforeach()
endif()

unset(_test_libs)

# This runs the blender_test executable with `--gtest_list_tests`, then
# exposes those tests individually to the ctest runner.
# See https://cmake.org/cmake/help/v3.18/module/GoogleTest.html
#
# We have our own modified copy of this CMake module.
include(GTest)

set(_GOOGLETEST_DISCOVER_TESTS_SCRIPT
  ${CMAKE_SOURCE_DIR}/build_files/cmake/Modules/GTestAddTests.cmake
)

if(APPLE)
  set(_test_release_dir ${TEST_INSTALL_DIR}/Blender.app/Contents/Resources/${BLENDER_VERSION})
else()
  set(_test_release_dir ${TEST_INSTALL_DIR}/${BLENDER_VERSION})
endif()

gtest_discover_tests(blender_test
  WORKING_DIRECTORY "${TEST_INSTALL_DIR}"
# So that it will run after the install phase that will copy the required libraries
  DISCOVERY_MODE PRE_TEST
# So that unit tests know where to find files:
  EXTRA_ARGS
    --test-assets-dir "${CMAKE_SOURCE_DIR}/../lib/tests"
    --test-release-dir "${_test_release_dir}"
)

unset(_test_release_dir)
