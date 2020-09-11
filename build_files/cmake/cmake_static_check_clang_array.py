#!/usr/bin/env python3

# <pep8 compliant>

import project_source_info
import subprocess
import sys
import os

USE_QUIET = (os.environ.get("QUIET", None) is not None)

CHECKER_IGNORE_PREFIX = [
    "extern",
    "intern/moto",
]

CHECKER_BIN = "python2"

CHECKER_ARGS = [
    os.path.join(os.path.dirname(__file__), "clang_array_check.py"),
    # not sure why this is needed, but it is.
    "-I" + os.path.join(project_source_info.SOURCE_DIR, "extern", "glew", "include"),
    # stupid but needed
    "-Dbool=char"
]


def main():
    source_info = project_source_info.build_info(ignore_prefix_list=CHECKER_IGNORE_PREFIX)

    check_commands = []
    for c, inc_dirs, defs in source_info:

        #~if "source/blender" not in c:
        #~    continue

        cmd = ([CHECKER_BIN] +
               CHECKER_ARGS +
               [c] +
               [("-I%s" % i) for i in inc_dirs] +
               [("-D%s" % d) for d in defs]
               )

        check_commands.append((c, cmd))

    process_functions = []

    def my_process(i, c, cmd):
        if not USE_QUIET:
            percent = 100.0 * (i / (len(check_commands) - 1))
            percent_str = "[" + ("%.2f]" % percent).rjust(7) + " %:"

            sys.stdout.flush()
            sys.stdout.write("%s %s\n" % (percent_str, c))

        return subprocess.Popen(cmd)

    for i, (c, cmd) in enumerate(check_commands):
        process_functions.append((my_process, (i, c, cmd)))

    project_source_info.queue_processes(process_functions)


if __name__ == "__main__":
    main()
