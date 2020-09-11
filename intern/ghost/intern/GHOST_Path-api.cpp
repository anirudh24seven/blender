/** \file
 * \ingroup GHOST
 */

#include <cstdio>

#include "GHOST_ISystemPaths.h"
#include "GHOST_Path-api.h"
#include "GHOST_Types.h"
#include "intern/GHOST_Debug.h"

GHOST_TSuccess GHOST_CreateSystemPaths(void)
{
  return GHOST_ISystemPaths::create();
}

GHOST_TSuccess GHOST_DisposeSystemPaths(void)
{
  return GHOST_ISystemPaths::dispose();
}

const GHOST_TUns8 *GHOST_getSystemDir(int version, const char *versionstr)
{
  GHOST_ISystemPaths *systemPaths = GHOST_ISystemPaths::get();
  return systemPaths ? systemPaths->getSystemDir(version, versionstr) : NULL;
}

const GHOST_TUns8 *GHOST_getUserDir(int version, const char *versionstr)
{
  GHOST_ISystemPaths *systemPaths = GHOST_ISystemPaths::get();
  return systemPaths ? systemPaths->getUserDir(version, versionstr) : NULL; /* shouldn't be NULL */
}

const GHOST_TUns8 *GHOST_getBinaryDir()
{
  GHOST_ISystemPaths *systemPaths = GHOST_ISystemPaths::get();
  return systemPaths ? systemPaths->getBinaryDir() : NULL; /* shouldn't be NULL */
}

void GHOST_addToSystemRecentFiles(const char *filename)
{
  GHOST_ISystemPaths *systemPaths = GHOST_ISystemPaths::get();
  if (systemPaths) {
    systemPaths->addToSystemRecentFiles(filename);
  }
}
