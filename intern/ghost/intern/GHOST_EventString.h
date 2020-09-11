/** \file
 * \ingroup GHOST
 * Declaration of GHOST_EventString class.
 */

#pragma once

#include "GHOST_Event.h"

/**
 * Generic class for events with string data
 */
class GHOST_EventString : public GHOST_Event {
 public:
  /**
   * Constructor.
   * \param msec  The time this event was generated.
   * \param type  The type of this event.
   * \param window The generating window (or NULL if system event).
   * \param data_ptr Pointer to the (unformatted) data associated with the event
   */
  GHOST_EventString(GHOST_TUns64 msec,
                    GHOST_TEventType type,
                    GHOST_IWindow *window,
                    GHOST_TEventDataPtr data_ptr)
      : GHOST_Event(msec, type, window)
  {
    m_data = data_ptr;
  }

  ~GHOST_EventString()
  {
    if (m_data)
      free(m_data);
  }
};
