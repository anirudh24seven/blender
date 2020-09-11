/** \file
 * \ingroup GHOST
 * Declaration of GHOST_DisplayManagerSDL class.
 */

#pragma once

#include "GHOST_DisplayManager.h"

extern "C" {
#include "SDL.h"
}

#if !SDL_VERSION_ATLEAST(2, 0, 0)
#  error "SDL 2.0 or newer is needed to build with Ghost"
#endif

class GHOST_SystemSDL;

class GHOST_DisplayManagerSDL : public GHOST_DisplayManager {
 public:
  GHOST_DisplayManagerSDL(GHOST_SystemSDL *system);

  GHOST_TSuccess getNumDisplays(GHOST_TUns8 &numDisplays) const;

  GHOST_TSuccess getNumDisplaySettings(GHOST_TUns8 display, GHOST_TInt32 &numSettings) const;

  GHOST_TSuccess getDisplaySetting(GHOST_TUns8 display,
                                   GHOST_TInt32 index,
                                   GHOST_DisplaySetting &setting) const;

  GHOST_TSuccess getCurrentDisplaySetting(GHOST_TUns8 display,
                                          GHOST_DisplaySetting &setting) const;

  GHOST_TSuccess getCurrentDisplayModeSDL(SDL_DisplayMode &mode) const;

  GHOST_TSuccess setCurrentDisplaySetting(GHOST_TUns8 display,
                                          const GHOST_DisplaySetting &setting);

 private:
  GHOST_SystemSDL *m_system;
  SDL_DisplayMode m_mode;
};
