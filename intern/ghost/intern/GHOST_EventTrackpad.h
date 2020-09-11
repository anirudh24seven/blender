/** \file
 * \ingroup GHOST
 * Declaration of GHOST_EventTrackpad class.
 */

#pragma once

#include "GHOST_Event.h"

/**
 * Trackpad (scroll, magnify, rotate, ...) event.
 */
class GHOST_EventTrackpad : public GHOST_Event {
 public:
  /**
   * Constructor.
   * \param msec      The time this event was generated.
   * \param window: The window of this event.
   * \param subtype   The subtype of the event.
   * \param x         The x-delta of the pan event.
   * \param y         The y-delta of the pan event.
   */
  GHOST_EventTrackpad(GHOST_TUns64 msec,
                      GHOST_IWindow *window,
                      GHOST_TTrackpadEventSubTypes subtype,
                      GHOST_TInt32 x,
                      GHOST_TInt32 y,
                      GHOST_TInt32 deltaX,
                      GHOST_TInt32 deltaY)
      : GHOST_Event(msec, GHOST_kEventTrackpad, window)
  {
    m_trackpadEventData.subtype = subtype;
    m_trackpadEventData.x = x;
    m_trackpadEventData.y = y;
    m_trackpadEventData.deltaX = deltaX;
    m_trackpadEventData.deltaY = deltaY;
    m_data = &m_trackpadEventData;
  }

 protected:
  /** The mouse pan data */
  GHOST_TEventTrackpadData m_trackpadEventData;
};
