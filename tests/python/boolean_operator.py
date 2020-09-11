# <pep8 compliant>

# To run all tests, use
# BLENDER_VERBOSE=1 blender path/to/bool_regression.blend --python path/to/boolean_operator.py -- --run-all-tests
# To run one test, use
# BLENDER_VERBOSE=1 blender path/to/bool_regression.blend --python path/to/boolean_operator.py -- --run-test <index>
# where <index> is the index of the test specified in the list tests.

import bpy
import os
import sys

sys.path.append(os.path.dirname(os.path.realpath(__file__)))
from modules.mesh_test import OperatorTest


def main():
    tests = [
        ['FACE', {0, 1, 2, 3, 4, 5}, 'Cubecube', 'Cubecube_result_1', 'intersect_boolean', {'operation': 'UNION', 'solver' : 'FAST'}],
        ['FACE', {0, 1, 2, 3, 4, 5}, 'Cubecube', 'Cubecube_result_2', 'intersect_boolean', {'operation': 'INTERSECT', 'solver' : 'FAST'}],
        ['FACE', {0, 1, 2, 3, 4, 5}, 'Cubecube', 'Cubecube_result_3', 'intersect_boolean', {'operation': 'DIFFERENCE', 'solver' : 'FAST'}],
        ['FACE', {0, 1, 2, 3, 4, 5}, 'Cubecube', 'Cubecube_result_4', 'intersect', {'separate_mode': 'CUT', 'solver' : 'FAST'}],
        ['FACE', {0, 1, 2, 3, 4, 5}, 'Cubecube', 'Cubecube_result_5', 'intersect', {'separate_mode': 'ALL', 'solver' : 'FAST'}],
        ['FACE', {0, 1, 2, 3, 4, 5}, 'Cubecube', 'Cubecube_result_6', 'intersect', {'separate_mode': 'NONE', 'solver' : 'FAST'}],
        ['FACE', {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, 'Cubecube', 'Cubecube_result_7', 'intersect',
         {'mode': 'SELECT', 'separate_mode': 'NONE', 'solver' : 'FAST'}],
        ['FACE', {6, 7, 8, 9, 10}, 'Cubecone', 'Cubecone_result_1', 'intersect_boolean', {'operation': 'UNION', 'solver' : 'FAST'}],
        ['FACE', {0, 1, 2, 3, 4, 5}, 'Cubecones', 'Cubecones_result_1', 'intersect_boolean', {'operation': 'UNION', 'solver' : 'FAST'}],
    ]

    operator_test = OperatorTest(tests)

    command = list(sys.argv)
    for i, cmd in enumerate(command):
        if cmd == "--run-all-tests":
            operator_test.run_all_tests()
            break
        elif cmd == "--run-test":
            index = int(command[i + 1])
            operator_test.run_test(index)
            break


if __name__ == "__main__":
    main()
