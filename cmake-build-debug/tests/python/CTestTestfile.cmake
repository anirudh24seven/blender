# CMake generated Testfile for 
# Source directory: /Users/anirudh/workspace/blender-git/blender/tests/python
# Build directory: /Users/anirudh/workspace/blender-git/blender/cmake-build-debug/tests/python
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(script_load_keymap "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_keymap_completeness.py")
set_tests_properties(script_load_keymap PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;47;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(script_load_addons "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_load_addons.py")
set_tests_properties(script_load_addons PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;52;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(script_load_modules "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_load_py_modules.py")
set_tests_properties(script_load_modules PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;57;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(script_bundled_modules "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_bundled_modules.py")
set_tests_properties(script_bundled_modules PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;62;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(script_pyapi_bpy_path "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_pyapi_bpy_path.py")
set_tests_properties(script_pyapi_bpy_path PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;77;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(script_pyapi_bpy_utils_units "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_pyapi_bpy_utils_units.py")
set_tests_properties(script_pyapi_bpy_utils_units PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;82;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(script_pyapi_mathutils "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_pyapi_mathutils.py")
set_tests_properties(script_pyapi_mathutils PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;87;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(script_pyapi_idprop "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_pyapi_idprop.py")
set_tests_properties(script_pyapi_idprop PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;92;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(script_pyapi_idprop_datablock "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_pyapi_idprop_datablock.py")
set_tests_properties(script_pyapi_idprop_datablock PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;97;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(script_pyapi_prop_array "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_pyapi_prop_array.py")
set_tests_properties(script_pyapi_prop_array PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;102;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(id_management "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_id_management.py")
set_tests_properties(id_management PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;110;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(blendfile_io "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_blendfile_io.py" "--" "--output-dir" "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/tests/blendfile_io/")
set_tests_properties(blendfile_io PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;118;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(blendfile_liblink "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_blendfile_liblink.py" "--" "--output-dir" "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/tests/blendfile_io/")
set_tests_properties(blendfile_liblink PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;124;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(bmesh_bevel "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/modeling/bevel_regression.blend" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bevel_operator.py" "--" "--run-all-tests")
set_tests_properties(bmesh_bevel PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;132;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(bmesh_boolean "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/modeling/bool_regression.blend" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/boolean_operator.py" "--" "--run-all-tests")
set_tests_properties(bmesh_boolean PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;140;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(bmesh_split_faces "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/modeling/split_faces_test.blend" "--python-text" "run_tests")
set_tests_properties(bmesh_split_faces PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;148;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(object_modifier_array "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/modifier_stack/array_test.blend" "--python-text" "run_tests.py")
set_tests_properties(object_modifier_array PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;156;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(modifiers "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/modeling/modifiers.blend" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/modifiers.py" "--" "--run-all-tests")
set_tests_properties(modifiers PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;162;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(physics_cloth "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/physics/cloth_test.blend" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/physics_cloth.py" "--" "--run-all-tests")
set_tests_properties(physics_cloth PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;170;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(physics_softbody "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/physics/softbody_test.blend" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/physics_softbody.py" "--" "--run-all-tests")
set_tests_properties(physics_softbody PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;178;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(constraints "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_constraints.py" "--" "--testdir" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/constraints")
set_tests_properties(constraints PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;186;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(operators "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/modeling/operators.blend" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/operators.py" "--" "--run-all-tests")
set_tests_properties(operators PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;195;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(bl_animation_fcurves "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_animation_fcurves.py" "--" "--testdir" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/animation")
set_tests_properties(bl_animation_fcurves PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;205;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(export_obj_cube "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/io_tests/blend_geometry/all_quads.blend" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_test.py" "--" "--run={'FINISHED'}&bpy.ops.export_scene.obj(filepath='/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/tests/io_tests/export_obj_cube.obj',use_selection=False)" "--md5_source=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/tests/io_tests/export_obj_cube.obj" "--md5_source=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/tests/io_tests/export_obj_cube.mtl" "--md5=95832f81160f07101dc566cb286a9f76" "--md5_method=FILE")
set_tests_properties(export_obj_cube PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;244;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(export_obj_nurbs "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/io_tests/blend_geometry/nurbs.blend" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_test.py" "--" "--run={'FINISHED'}&bpy.ops.export_scene.obj(filepath='/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/tests/io_tests/export_obj_nurbs.obj',use_selection=False,use_nurbs=True)" "--md5_source=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/tests/io_tests/export_obj_nurbs.obj" "--md5_source=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/tests/io_tests/export_obj_nurbs.mtl" "--md5=a733ae4fa4a591ea9b0912da3af042de" "--md5_method=FILE")
set_tests_properties(export_obj_nurbs PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;254;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(import_ply_cube "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_test.py" "--" "--run={'FINISHED'}&bpy.ops.import_mesh.ply(filepath='/Users/anirudh/workspace/blender-git/blender/../lib/tests/io_tests/ply/cube_ascii.ply')" "--md5=527134343c27fc0ea73115b85fbfd3ac" "--md5_method=SCENE" "--write-blend=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/tests/io_tests/import_ply_cube.blend")
set_tests_properties(import_ply_cube PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;280;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(import_ply_bunny "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_test.py" "--" "--run={'FINISHED'}&bpy.ops.import_mesh.ply(filepath='/Users/anirudh/workspace/blender-git/blender/../lib/tests/io_tests/ply/bunny2.ply')" "--md5=6ea5b8533400a17accf928b8fd024eaa" "--md5_method=SCENE" "--write-blend=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/tests/io_tests/import_ply_bunny.blend")
set_tests_properties(import_ply_bunny PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;288;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(import_ply_small_holes "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_test.py" "--" "--run={'FINISHED'}&bpy.ops.import_mesh.ply(filepath='/Users/anirudh/workspace/blender-git/blender/../lib/tests/io_tests/ply/many_small_holes.ply')" "--md5=c3093e26ecae5b6d59fbbcf2a0d0b39f" "--md5_method=SCENE" "--write-blend=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/tests/io_tests/import_ply_small_holes.blend")
set_tests_properties(import_ply_small_holes PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;296;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(export_ply_vertices "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/io_tests/blend_geometry/vertices.blend" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_test.py" "--" "--run={'FINISHED'}&bpy.ops.export_mesh.ply(filepath='/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/tests/io_tests/export_ply_vertices.ply')" "--md5_source=/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/tests/io_tests/export_ply_vertices.ply" "--md5=ee6ce2e69c1d9a7418ff0548f6338f70" "--md5_method=FILE")
set_tests_properties(export_ply_vertices PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;326;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(alembic_export_tests "/Users/anirudh/workspace/blender-git/blender/../lib/darwin/python/bin/python3.7m" "/Users/anirudh/workspace/blender-git/blender/tests/python/alembic_export_tests.py" "--blender" "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin//Blender.app/Contents/MacOS/Blender" "--testdir" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/alembic" "--alembic-root" "/Users/anirudh/workspace/blender-git/lib/darwin/alembic")
set_tests_properties(alembic_export_tests PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;38;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;656;add_python_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(script_alembic_io "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin/Blender.app/Contents/MacOS/Blender" "--background" "-noaudio" "--factory-startup" "--debug-memory" "--debug-exit-on-error" "--python-exit-code" "1" "--python" "/Users/anirudh/workspace/blender-git/blender/tests/python/bl_alembic_io_test.py" "--" "--testdir" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/alembic")
set_tests_properties(script_alembic_io PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;22;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;664;add_blender_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
add_test(ffmpeg "/Users/anirudh/workspace/blender-git/blender/../lib/darwin/python/bin/python3.7m" "/Users/anirudh/workspace/blender-git/blender/tests/python/ffmpeg_tests.py" "--blender" "/Users/anirudh/workspace/blender-git/blender/cmake-build-debug/bin//Blender.app/Contents/MacOS/Blender" "--testdir" "/Users/anirudh/workspace/blender-git/blender/../lib/tests/ffmpeg")
set_tests_properties(ffmpeg PROPERTIES  ENVIRONMENT "LSAN_OPTIONS=exitcode=0" _BACKTRACE_TRIPLES "/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;38;add_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;673;add_python_test;/Users/anirudh/workspace/blender-git/blender/tests/python/CMakeLists.txt;0;")
subdirs("collada")
