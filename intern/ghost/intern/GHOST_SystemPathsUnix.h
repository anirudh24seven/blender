/** \file
 * \ingroup GHOST
 */

#pragma once

#include "../GHOST_Types.h"
#include "GHOST_SystemPaths.h"

class GHOST_SystemPathsUnix : public GHOST_SystemPaths {
 public:
  /**
   * Constructor
   * this class should only be instantiated by GHOST_ISystem.
   */
  GHOST_SystemPathsUnix();

  /**
   * Destructor.
   */
  ~GHOST_SystemPathsUnix();

  /**
   * Determine the base dir in which shared resources are located. It will first try to use
   * "unpack and run" path, then look for properly installed path, including versioning.
   * \return Unsigned char string pointing to system dir (eg `/usr/share/blender/`).
   */
  const GHOST_TUns8 *getSystemDir(int version, const char *versionstr) const;

  /**
   * Determine the base dir in which user configuration is stored, including versioning.
   * If needed, it will create the base directory.
   * \return Unsigned char string pointing to user dir (eg `~/.config/.blender/`).
   */
  const GHOST_TUns8 *getUserDir(int version, const char *versionstr) const;

  /**
   * Determine the directory of the current binary
   * \return Unsigned char string pointing to the binary dir
   */
  const GHOST_TUns8 *getBinaryDir() const;

  /**
   * Add the file to the operating system most recently used files
   */
  void addToSystemRecentFiles(const char *filename) const;
};
