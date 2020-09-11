/** \file
 * \ingroup GHOST
 */

#include "GHOST_SystemPathsWin32.h"

#ifndef _WIN32_IE
#  define _WIN32_IE 0x0501
#endif
#include "utfconv.h"
#include <shlobj.h>

GHOST_SystemPathsWin32::GHOST_SystemPathsWin32()
{
}

GHOST_SystemPathsWin32::~GHOST_SystemPathsWin32()
{
}

const GHOST_TUns8 *GHOST_SystemPathsWin32::getSystemDir(int, const char *versionstr) const
{
  /* 1 utf-16 might translante into 3 utf-8. 2 utf-16 translates into 4 utf-8*/
  static char knownpath[MAX_PATH * 3 + 128] = {0};
  PWSTR knownpath_16 = NULL;

  HRESULT hResult = SHGetKnownFolderPath(
      FOLDERID_ProgramData, KF_FLAG_DEFAULT, NULL, &knownpath_16);

  if (hResult == S_OK) {
    conv_utf_16_to_8(knownpath_16, knownpath, MAX_PATH * 3);
    CoTaskMemFree(knownpath_16);
    strcat(knownpath, "\\Blender Foundation\\Blender\\");
    strcat(knownpath, versionstr);
    return (GHOST_TUns8 *)knownpath;
  }

  return NULL;
}

const GHOST_TUns8 *GHOST_SystemPathsWin32::getUserDir(int, const char *versionstr) const
{
  static char knownpath[MAX_PATH * 3 + 128] = {0};
  PWSTR knownpath_16 = NULL;

  HRESULT hResult = SHGetKnownFolderPath(
      FOLDERID_RoamingAppData, KF_FLAG_DEFAULT, NULL, &knownpath_16);

  if (hResult == S_OK) {
    conv_utf_16_to_8(knownpath_16, knownpath, MAX_PATH * 3);
    CoTaskMemFree(knownpath_16);
    strcat(knownpath, "\\Blender Foundation\\Blender\\");
    strcat(knownpath, versionstr);
    return (GHOST_TUns8 *)knownpath;
  }

  return NULL;
}

const GHOST_TUns8 *GHOST_SystemPathsWin32::getBinaryDir() const
{
  static char fullname[MAX_PATH * 3] = {0};
  wchar_t fullname_16[MAX_PATH * 3];

  if (GetModuleFileNameW(0, fullname_16, MAX_PATH)) {
    conv_utf_16_to_8(fullname_16, fullname, MAX_PATH * 3);
    return (GHOST_TUns8 *)fullname;
  }

  return NULL;
}

void GHOST_SystemPathsWin32::addToSystemRecentFiles(const char *filename) const
{
  /* SHARD_PATH resolves to SHARD_PATHA for non-UNICODE build */
  UTF16_ENCODE(filename);
  SHAddToRecentDocs(SHARD_PATHW, filename_16);
  UTF16_UN_ENCODE(filename);
}
