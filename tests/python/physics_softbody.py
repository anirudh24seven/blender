# <pep8 compliant>

import os
import sys

import bpy

sys.path.append(os.path.dirname(os.path.realpath(__file__)))
from modules.mesh_test import ModifierTest, PhysicsSpec


def main():
    test = [
      ["testSoftBody", "expectedSoftBody",
       [PhysicsSpec('Softbody', 'SOFT_BODY', {'use_goal': False, 'bend': 8, 'pull': 0.8, 'push': 0.8}, 45)]],
    ]
    softBody_test = ModifierTest(test)

    command = list(sys.argv)
    for i, cmd in enumerate(command):
        if cmd == "--run-all-tests":
            softBody_test.apply_modifiers = True
            softBody_test.run_all_tests()
            break
        elif cmd == "--run-test":
            softBody_test.apply_modifiers = False
            index = int(command[i + 1])
            softBody_test.run_test(index)
            break


if __name__ == "__main__":
    main()
