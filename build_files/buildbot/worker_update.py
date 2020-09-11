# <pep8 compliant>

import buildbot_utils
import os
import sys

if __name__ == "__main__":
    builder = buildbot_utils.create_builder_from_arguments()
    os.chdir(builder.blender_dir)

    # Run make update which handles all libraries and submodules.
    make_update = os.path.join(builder.blender_dir, "build_files", "utils", "make_update.py")
    buildbot_utils.call([sys.executable, make_update, '--no-blender', "--use-tests", "--use-centos-libraries"])
