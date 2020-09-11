# <pep8 compliant>

import buildbot_utils
import os
import sys

def get_ctest_arguments(builder):
    args = ['--output-on-failure']
    if builder.platform == 'win':
        args += ['-C', 'Release']
    return args

def test(builder):
    os.chdir(builder.build_dir)

    command = builder.command_prefix  + ['ctest'] + get_ctest_arguments(builder)
    buildbot_utils.call(command)

if __name__ == "__main__":
    builder = buildbot_utils.create_builder_from_arguments()
    test(builder)
