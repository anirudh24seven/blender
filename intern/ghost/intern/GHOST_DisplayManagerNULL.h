/** \file
 * \ingroup GHOST
 * Declaration of GHOST_DisplayManagerNULL class.
 */

#pragma once

#include "GHOST_DisplayManager.h"
#include "GHOST_SystemNULL.h"

class GHOST_SystemNULL;

class GHOST_DisplayManagerNULL : public GHOST_DisplayManager {
 public:
  GHOST_DisplayManagerNULL(GHOST_SystemNULL *system) : GHOST_DisplayManager(), m_system(system)
  { /* nop */
  }
  GHOST_TSuccess getNumDisplays(GHOST_TUns8 &numDisplays) const
  {
    return GHOST_kFailure;
  }
  GHOST_TSuccess getNumDisplaySettings(GHOST_TUns8 display, GHOST_TInt32 &numSettings) const
  {
    return GHOST_kFailure;
  }
  GHOST_TSuccess getDisplaySetting(GHOST_TUns8 display,
                                   GHOST_TInt32 index,
                                   GHOST_DisplaySetting &setting) const
  {
    return GHOST_kFailure;
  }
  GHOST_TSuccess getCurrentDisplaySetting(GHOST_TUns8 display, GHOST_DisplaySetting &setting) const
  {
    return getDisplaySetting(display, GHOST_TInt32(0), setting);
  }
  GHOST_TSuccess setCurrentDisplaySetting(GHOST_TUns8 display, const GHOST_DisplaySetting &setting)
  {
    return GHOST_kSuccess;
  }

 private:
  GHOST_SystemNULL *m_system;
};
