#!/usr/bin/env python3

# <pep8 compliant>


def print_help(targets):
    print("CMake quicky wrapper, no valid targets given.")
    print(" * targets can contain a subset of the full target name.")
    print(" * arguments with a '-' prefix are passed onto make.")
    print(" * this must run from the cmake build dir")
    print(" * alias this with a short command for speedy access, in bash:")
    print("   alias mk='../blender/build_files/cmake/example_scripts/make_quicky.py'")
    print("")
    print(" eg: make_quicky.py -j3 extern python")
    print(" ...will execute")
    print(" make -j3 extern_binreloc extern_glew bf_python bf_python_ext blender/fast")
    print("")
    print("Target List:")
    for t in targets:
        print("    %s" % t)
    print("...exiting")


def main():
    targets = set()

    # collect targets
    makefile = open("Makefile", "r")
    for line in makefile:
        line = line.rstrip()
        if not line or line[0] in ". \t@$#":
            continue

        line = line.split("#", 1)[0]
        if ":" not in line:
            continue

        line = line.split(":", 1)[0]

        if "/" in line:  # cmake terget options, dont need these
            continue

        targets.add(line)
    makefile.close()

    # remove cmake targets
    bad = set([
        "help",
        "clean",
        "all",
        "preinstall",
        "install",
        "default_target",
        "edit_cache",
        "cmake_force",
        "rebuild_cache",
        "depend",
        "cmake_check_build_system",
    ])

    targets -= set(bad)

    # parse args
    targets = list(targets)
    targets.sort()

    import sys
    if len(sys.argv) == 1:
        print_help(targets)
        return

    targets_new = []
    args = []
    for arg in sys.argv[1:]:
        if arg[0] in "/-":
            args.append(arg)
        else:
            found = False
            for t in targets:
                if arg in t and t not in targets_new:
                    targets_new.append(t)
                    found = True

            if not found:
                print("Error '%s' not found in...")
                for t in targets:
                    print("    %s" % t)
                print("...aborting.")
                return

    # execute
    cmd = ["make"] + args + targets_new + ["blender/fast"]
    print("cmake building with targets: %s" % " ".join(targets_new))
    print("executing: %s" % " ".join(cmd))

    import subprocess
    subprocess.call(cmd)

if __name__ == "__main__":
    main()
