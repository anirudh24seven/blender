/** \file
 * \ingroup GHOST
 */

#pragma once

#include "GHOST_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

GHOST_DECLARE_HANDLE(GHOST_SystemPathsHandle);

/**
 * Creates the one and only instance of the system path access.
 * \return An indication of success.
 */
extern GHOST_TSuccess GHOST_CreateSystemPaths(void);

/**
 * Disposes the one and only system.
 * \return An indication of success.
 */
extern GHOST_TSuccess GHOST_DisposeSystemPaths(void);

/**
 * Determine the base dir in which shared resources are located. It will first try to use
 * "unpack and run" path, then look for properly installed path, including versioning.
 * \return Unsigned char string pointing to system dir (eg /usr/share/blender/).
 */
extern const GHOST_TUns8 *GHOST_getSystemDir(int version, const char *versionstr);

/**
 * Determine the base dir in which user configuration is stored, including versioning.
 * \return Unsigned char string pointing to user dir (eg ~).
 */
extern const GHOST_TUns8 *GHOST_getUserDir(int version, const char *versionstr);

/**
 * Determine the dir in which the binary file is found.
 * \return Unsigned char string pointing to binary dir (eg ~/usr/local/bin/).
 */
extern const GHOST_TUns8 *GHOST_getBinaryDir(void);

/**
 * Add the file to the operating system most recently used files
 */
extern void GHOST_addToSystemRecentFiles(const char *filename);

#ifdef __cplusplus
}
#endif
