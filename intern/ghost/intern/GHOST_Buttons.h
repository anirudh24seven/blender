/** \file
 * \ingroup GHOST
 * Declaration of GHOST_Buttons struct.
 */

#pragma once

#include "GHOST_Types.h"

/**
 * This struct stores the state of the mouse buttons.
 * Buttons can be set using button masks.
 */
struct GHOST_Buttons {
  /**
   * Constructor.
   */
  GHOST_Buttons();

  ~GHOST_Buttons();

  /**
   * Returns the state of a single button.
   * \param mask Key button to return.
   * \return The state of the button (pressed == true).
   */
  bool get(GHOST_TButtonMask mask) const;

  /**
   * Updates the state of a single button.
   * \param mask Button state to update.
   * \param down The new state of the button.
   */
  void set(GHOST_TButtonMask mask, bool down);

  /**
   * Sets the state of all buttons to up.
   */
  void clear();

  GHOST_TUns8 m_ButtonLeft : 1;
  GHOST_TUns8 m_ButtonMiddle : 1;
  GHOST_TUns8 m_ButtonRight : 1;
};
