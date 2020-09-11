/** \file
 * \ingroup GHOST
 */

#pragma once

#ifndef WITH_INPUT_NDOF
#  error NDOF code included in non-NDOF-enabled build
#endif

#include "GHOST_Event.h"

class GHOST_EventNDOFMotion : public GHOST_Event {
 protected:
  GHOST_TEventNDOFMotionData m_axisData;

 public:
  GHOST_EventNDOFMotion(GHOST_TUns64 time, GHOST_IWindow *window)
      : GHOST_Event(time, GHOST_kEventNDOFMotion, window)
  {
    m_data = &m_axisData;
  }
};

class GHOST_EventNDOFButton : public GHOST_Event {
 protected:
  GHOST_TEventNDOFButtonData m_buttonData;

 public:
  GHOST_EventNDOFButton(GHOST_TUns64 time, GHOST_IWindow *window)
      : GHOST_Event(time, GHOST_kEventNDOFButton, window)
  {
    m_data = &m_buttonData;
  }
};
