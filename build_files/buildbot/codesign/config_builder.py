# <pep8 compliant>

# Configuration of a code signer which is specific to the code running from
# buildbot's worker.

import sys

from pathlib import Path

import codesign.util as util

from codesign.config_common import *

platform = util.get_current_platform()
if platform == util.Platform.LINUX:
    SHARED_STORAGE_DIR = Path('/data/codesign')
elif platform == util.Platform.WINDOWS:
    SHARED_STORAGE_DIR = Path('Z:\\codesign')
elif platform == util.Platform.MACOS:
    SHARED_STORAGE_DIR = Path('/Volumes/codesign_macos/codesign')

# https://docs.python.org/3/library/logging.config.html#configuration-dictionary-schema
LOGGING = {
    'version': 1,
    'formatters': {
        'default': {'format': '%(asctime)-15s %(levelname)8s %(name)s %(message)s'}
    },
    'handlers': {
        'console': {
            'class': 'logging.StreamHandler',
            'formatter': 'default',
            'stream': 'ext://sys.stderr',
        }
    },
    'loggers': {
        'codesign': {'level': 'INFO'},
    },
    'root': {
        'level': 'WARNING',
        'handlers': [
            'console',
        ],
    }
}
