# <pep8 compliant>

import sys

from enum import Enum
from pathlib import Path


class Platform(Enum):
    LINUX = 1
    MACOS = 2
    WINDOWS = 3


def get_current_platform() -> Platform:
    if sys.platform == 'linux':
        return Platform.LINUX
    elif sys.platform == 'darwin':
        return Platform.MACOS
    elif sys.platform == 'win32':
        return Platform.WINDOWS
    raise Exception(f'Unknown platform {sys.platform}')


def ensure_file_does_not_exist_or_die(filepath: Path) -> None:
    """
    If the file exists, unlink it.
    If the file path exists and is not a file an assert will trigger.
    If the file path does not exists nothing happens.
    """
    if not filepath.exists():
        return
    if not filepath.is_file():
        # TODO(sergey): Provide information about what the filepath actually is.
        raise SystemExit(f'{filepath} is expected to be a file, but is not')
    filepath.unlink()
