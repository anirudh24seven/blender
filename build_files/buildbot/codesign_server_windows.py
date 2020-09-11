#!/usr/bin/env python3

# <pep8 compliant>

# Implementation of codesign server for Windows.
#
# NOTE: If signtool.exe is not in the PATH use codesign_server_windows.bat

import logging.config
import shutil

from pathlib import Path
from typing import List

import codesign.util as util

from codesign.windows_code_signer import WindowsCodeSigner
import codesign.config_server

if __name__ == "__main__":
    logging.config.dictConfig(codesign.config_server.LOGGING)

    logger = logging.getLogger(__name__)
    logger_server = logger.getChild('server')

    # TODO(sergey): Consider moving such sanity checks into
    # CodeSigner.check_environment_or_die().
    if not shutil.which('signtool.exe'):
        if util.get_current_platform() == util.Platform.WINDOWS:
            raise SystemExit("signtool.exe is not found in %PATH%")
        logger_server.info(
            'signtool.exe not found, '
            'but will not be used on this foreign platform')

    code_signer = WindowsCodeSigner(codesign.config_server)
    code_signer.run_signing_server()
