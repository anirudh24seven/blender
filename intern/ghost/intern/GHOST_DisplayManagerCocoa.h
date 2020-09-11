/** \file
 * \ingroup GHOST
 * Declaration of GHOST_DisplayManagerCocoa class.
 */

#pragma once

#ifndef __APPLE__
#  error Apple only!
#endif  // __APPLE__

#include "GHOST_DisplayManager.h"

/**
 * Manages system displays  (Mac OSX/Cocoa implementation).
 * \see GHOST_DisplayManager
 */
class GHOST_DisplayManagerCocoa : public GHOST_DisplayManager {
 public:
  /**
   * Constructor.
   */
  GHOST_DisplayManagerCocoa(void);

  /**
   * Returns the number of display devices on this system.
   * \param numDisplays The number of displays on this system.
   * \return Indication of success.
   */
  GHOST_TSuccess getNumDisplays(GHOST_TUns8 &numDisplays) const;

  /**
   * Returns the number of display settings for this display device.
   * \param display The index of the display to query with 0 <= display < getNumDisplays().
   * \param numSetting: The number of settings of the display device with this index.
   * \return Indication of success.
   */
  GHOST_TSuccess getNumDisplaySettings(GHOST_TUns8 display, GHOST_TInt32 &numSettings) const;

  /**
   * Returns the current setting for this display device.
   * \param display The index of the display to query with 0 <= display < getNumDisplays().
   * \param index   The setting index to be returned.
   * \param setting The setting of the display device with this index.
   * \return Indication of success.
   */
  GHOST_TSuccess getDisplaySetting(GHOST_TUns8 display,
                                   GHOST_TInt32 index,
                                   GHOST_DisplaySetting &setting) const;

  /**
   * Returns the current setting for this display device.
   * \param display The index of the display to query with 0 <= display < getNumDisplays().
   * \param setting The current setting of the display device with this index.
   * \return Indication of success.
   */
  GHOST_TSuccess getCurrentDisplaySetting(GHOST_TUns8 display,
                                          GHOST_DisplaySetting &setting) const;

  /**
   * Changes the current setting for this display device.
   * \param display The index of the display to query with 0 <= display < getNumDisplays().
   * \param setting The current setting of the display device with this index.
   * \return Indication of success.
   */
  GHOST_TSuccess setCurrentDisplaySetting(GHOST_TUns8 display,
                                          const GHOST_DisplaySetting &setting);

 protected:
  // Do not cache values as OS X supports screen hot plug
  /** Cached number of displays. */
  // CGDisplayCount m_numDisplays;
  /** Cached display id's for each display. */
  // CGDirectDisplayID* m_displayIDs;
};
