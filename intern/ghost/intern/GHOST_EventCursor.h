/** \file
 * \ingroup GHOST
 * Declaration of GHOST_EventCursor class.
 */

#pragma once

#include "GHOST_Event.h"

/**
 * Cursor event.
 */
class GHOST_EventCursor : public GHOST_Event {
 public:
  /**
   * Constructor.
   * \param msec      The time this event was generated.
   * \param type      The type of this event.
   * \param x         The x-coordinate of the location the cursor was at the time of the event.
   * \param y         The y-coordinate of the location the cursor was at the time of the event.
   * \param tablet    The tablet data associated with this event.
   */
  GHOST_EventCursor(GHOST_TUns64 msec,
                    GHOST_TEventType type,
                    GHOST_IWindow *window,
                    GHOST_TInt32 x,
                    GHOST_TInt32 y,
                    const GHOST_TabletData &tablet)
      : GHOST_Event(msec, type, window)
  {
    m_cursorEventData.x = x;
    m_cursorEventData.y = y;
    m_cursorEventData.tablet = tablet;
    m_data = &m_cursorEventData;
  }

 protected:
  /** The x,y-coordinates of the cursor position. */
  GHOST_TEventCursorData m_cursorEventData;
};
