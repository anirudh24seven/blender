# <pep8 compliant>

import os
import sys

import bpy

sys.path.append(os.path.dirname(os.path.realpath(__file__)))
from modules.mesh_test import ModifierTest, PhysicsSpec


def main():
    test = [
        ["testCloth", "expectedCloth",
         [PhysicsSpec('Cloth', 'CLOTH', {'quality': 5}, 35)]],
    ]
    cloth_test = ModifierTest(test, threshold=1e-3)

    command = list(sys.argv)
    for i, cmd in enumerate(command):
        if cmd == "--run-all-tests":
            cloth_test.apply_modifiers = True
            cloth_test.run_all_tests()
            break
        elif cmd == "--run-test":
            cloth_test.apply_modifiers = False
            index = int(command[i + 1])
            cloth_test.run_test(index)
            break


if __name__ == "__main__":
    main()
