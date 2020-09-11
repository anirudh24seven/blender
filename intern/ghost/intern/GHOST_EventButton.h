/** \file
 * \ingroup GHOST
 * Declaration of GHOST_EventButton class.
 */

#pragma once

#include "GHOST_Event.h"
#include "GHOST_Window.h"

/**
 * Mouse button event.
 */
class GHOST_EventButton : public GHOST_Event {
 public:
  /**
   * Constructor.
   * \param time      The time this event was generated.
   * \param type      The type of this event.
   * \param window    The window of this event.
   * \param button    The state of the buttons were at the time of the event.
   * \param tablet    The tablet data associated with this event.
   */
  GHOST_EventButton(GHOST_TUns64 time,
                    GHOST_TEventType type,
                    GHOST_IWindow *window,
                    GHOST_TButtonMask button,
                    const GHOST_TabletData &tablet)
      : GHOST_Event(time, type, window)
  {
    m_buttonEventData.button = button;
    m_buttonEventData.tablet = tablet;
    m_data = &m_buttonEventData;
  }

 protected:
  /** The button event data. */
  GHOST_TEventButtonData m_buttonEventData;
};
