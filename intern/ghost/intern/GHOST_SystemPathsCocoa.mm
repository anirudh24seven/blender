/** The Original Code is Copyright (C) 2010 Blender Foundation.
 * All rights reserved.
 *
 *
 */

#import <Foundation/Foundation.h>

#include "GHOST_SystemPathsCocoa.h"

#pragma mark initialization/finalization

GHOST_SystemPathsCocoa::GHOST_SystemPathsCocoa()
{
}

GHOST_SystemPathsCocoa::~GHOST_SystemPathsCocoa()
{
}

#pragma mark Base directories retrieval

const GHOST_TUns8 *GHOST_SystemPathsCocoa::getSystemDir(int, const char *versionstr) const
{
  static char tempPath[512] = "";
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  NSString *basePath;
  NSArray *paths;

  paths = NSSearchPathForDirectoriesInDomains(
      NSApplicationSupportDirectory, NSLocalDomainMask, YES);

  if ([paths count] > 0)
    basePath = [paths objectAtIndex:0];
  else {
    [pool drain];
    return NULL;
  }

  snprintf(tempPath,
           sizeof(tempPath),
           "%s/Blender/%s",
           [basePath cStringUsingEncoding:NSASCIIStringEncoding],
           versionstr);

  [pool drain];
  return (GHOST_TUns8 *)tempPath;
}

const GHOST_TUns8 *GHOST_SystemPathsCocoa::getUserDir(int, const char *versionstr) const
{
  static char tempPath[512] = "";
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  NSString *basePath;
  NSArray *paths;

  paths = NSSearchPathForDirectoriesInDomains(
      NSApplicationSupportDirectory, NSUserDomainMask, YES);

  if ([paths count] > 0)
    basePath = [paths objectAtIndex:0];
  else {
    [pool drain];
    return NULL;
  }

  snprintf(tempPath,
           sizeof(tempPath),
           "%s/Blender/%s",
           [basePath cStringUsingEncoding:NSASCIIStringEncoding],
           versionstr);

  [pool drain];
  return (GHOST_TUns8 *)tempPath;
}

const GHOST_TUns8 *GHOST_SystemPathsCocoa::getBinaryDir() const
{
  static GHOST_TUns8 tempPath[512] = "";
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  NSString *basePath;

  basePath = [[NSBundle mainBundle] bundlePath];

  if (basePath == nil) {
    [pool drain];
    return NULL;
  }

  strcpy((char *)tempPath, [basePath cStringUsingEncoding:NSASCIIStringEncoding]);

  [pool drain];
  return tempPath;
}

void GHOST_SystemPathsCocoa::addToSystemRecentFiles(const char *filename) const
{
  /* TODO: implement for macOS */
}
