#!/usr/bin/env python3

# <pep8 compliant>

# NOTE: This is a no-op signer (since there isn't really a procedure to sign
# Linux binaries yet). Used to debug and verify the code signing routines on
# a Linux environment.

import logging.config
from pathlib import Path
from typing import List

from codesign.linux_code_signer import LinuxCodeSigner
import codesign.config_server

if __name__ == "__main__":
    logging.config.dictConfig(codesign.config_server.LOGGING)
    code_signer = LinuxCodeSigner(codesign.config_server)
    code_signer.run_signing_server()
