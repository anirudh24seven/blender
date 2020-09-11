#!/usr/bin/env python3

# <pep8 compliant>

import logging.config
from pathlib import Path
from typing import List

from codesign.macos_code_signer import MacOSCodeSigner
import codesign.config_server

if __name__ == "__main__":
    entitlements_file = codesign.config_server.MACOS_ENTITLEMENTS_FILE
    if not entitlements_file.exists():
        raise SystemExit(
            'Entitlements file {entitlements_file} does not exist.')
    if not entitlements_file.is_file():
        raise SystemExit(
            'Entitlements file {entitlements_file} is not a file.')

    logging.config.dictConfig(codesign.config_server.LOGGING)
    code_signer = MacOSCodeSigner(codesign.config_server)
    code_signer.run_signing_server()
