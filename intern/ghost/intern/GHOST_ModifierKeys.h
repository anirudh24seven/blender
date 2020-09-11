/** \file
 * \ingroup GHOST
 * Declaration of GHOST_ModifierKeys struct.
 */

#pragma once

#include "GHOST_Types.h"

/**
 * Stores the state of modifier keys.
 * Discriminates between left and right modifier keys.
 */
struct GHOST_ModifierKeys {
  /**
   * Constructor.
   */
  GHOST_ModifierKeys();

  ~GHOST_ModifierKeys();

  /**
   * Returns the modifier key's key code from a modifier key mask.
   * \param mask The mask of the modifier key.
   * \return The modifier key's key code.
   */
  static GHOST_TKey getModifierKeyCode(GHOST_TModifierKeyMask mask);

  /**
   * Returns the state of a single modifier key.
   * \param mask: Key state to return.
   * \return The state of the key (pressed == true).
   */
  bool get(GHOST_TModifierKeyMask mask) const;

  /**
   * Updates the state of a single modifier key.
   * \param mask: Key state to update.
   * \param down: The new state of the key.
   */
  void set(GHOST_TModifierKeyMask mask, bool down);

  /**
   * Sets the state of all modifier keys to up.
   */
  void clear();

  /**
   * Determines whether to modifier key states are equal.
   * \param keys: The modifier key state to compare to.
   * \return Indication of equality.
   */
  bool equals(const GHOST_ModifierKeys &keys) const;

  /** Bitfield that stores the appropriate key state. */
  GHOST_TUns8 m_LeftShift : 1;
  /** Bitfield that stores the appropriate key state. */
  GHOST_TUns8 m_RightShift : 1;
  /** Bitfield that stores the appropriate key state. */
  GHOST_TUns8 m_LeftAlt : 1;
  /** Bitfield that stores the appropriate key state. */
  GHOST_TUns8 m_RightAlt : 1;
  /** Bitfield that stores the appropriate key state. */
  GHOST_TUns8 m_LeftControl : 1;
  /** Bitfield that stores the appropriate key state. */
  GHOST_TUns8 m_RightControl : 1;
  /** Bitfield that stores the appropriate key state. */
  GHOST_TUns8 m_OS : 1;
};
