# <pep8 compliant>

from pathlib import Path

# Timeout in seconds for the signing process.
#
# This is how long buildbot packing step will wait signing server to
# perform signing.
#
# NOTE: Notarization could take a long time, hence the rather high value
# here. Might consider using different timeout for different platforms.
TIMEOUT_IN_SECONDS = 45 * 60 * 60

# Directory which is shared across buildbot worker and signing server.
#
# This is where worker puts files requested for signing as well as where
# server puts signed files.
SHARED_STORAGE_DIR: Path
