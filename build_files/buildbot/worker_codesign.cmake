# This is a script which is used as POST-INSTALL one for regular CMake's
# INSTALL target.
# It is used by buildbot workers to sign every binary which is going into
# the final buundle.

# On Windows Python 3 there only is python.exe, no python3.exe.
#
# On other platforms it is possible to have python2 and python3, and a
# symbolic link to python to either of them. So on those platforms use
# an explicit Python version.
if(WIN32)
  set(PYTHON_EXECUTABLE python)
else()
  set(PYTHON_EXECUTABLE python3)
endif()

execute_process(
  COMMAND ${PYTHON_EXECUTABLE} "${CMAKE_CURRENT_LIST_DIR}/worker_codesign.py"
          "${CMAKE_INSTALL_PREFIX}"
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
  RESULT_VARIABLE exit_code
)

if(NOT exit_code EQUAL "0")
    message(FATAL_ERROR "Non-zero exit code of codesign tool")
endif()
