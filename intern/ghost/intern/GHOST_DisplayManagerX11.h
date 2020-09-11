/** \file
 * \ingroup GHOST
 * Declaration of GHOST_DisplayManagerX11 class.
 */

#pragma once

#include "GHOST_DisplayManager.h"

class GHOST_SystemX11;

/**
 * Manages system displays  (X11 implementation).
 */
class GHOST_DisplayManagerX11 : public GHOST_DisplayManager {
 public:
  /**
   * Constructor.
   */
  GHOST_DisplayManagerX11(GHOST_SystemX11 *system);

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

 private:
  GHOST_SystemX11 *m_system;
};
