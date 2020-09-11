# <pep8-80 compliant>

"""
Give access to blender data and utility functions.
"""

__all__ = (
    "app",
    "context",
    "data",
    "ops",
    "path",
    "props",
    "types",
    "utils",
)


# internal blender C module
from _bpy import (
    app,
    context,
    data,
    msgbus,
    props,
    types,
)

# python modules
from . import (
    path,
    utils,
)

# fake operator module
from .ops import ops_fake_module as ops


def main():
    import sys

    # Possibly temp. addons path
    from os.path import join, dirname
    sys.path.extend([
        join(dirname(dirname(dirname(__file__))), "addons", "modules"),
        join(utils.user_resource('SCRIPTS'), "addons", "modules"),
    ])

    # fake module to allow:
    #   from bpy.types import Panel
    sys.modules.update({
        "bpy.app": app,
        "bpy.app.handlers": app.handlers,
        "bpy.app.translations": app.translations,
        "bpy.types": types,
    })

    # Initializes Python classes.
    # (good place to run a profiler or trace).
    utils.load_scripts()


main()

del main
