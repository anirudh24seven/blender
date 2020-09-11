/** \file
 * \ingroup GHOST
 * Declaration of GHOST_SystemNULL class.
 */

#pragma once

#include "../GHOST_Types.h"
#include "GHOST_DisplayManagerNULL.h"
#include "GHOST_System.h"
#include "GHOST_WindowNULL.h"

class GHOST_WindowNULL;

class GHOST_SystemNULL : public GHOST_System {
 public:
  GHOST_SystemNULL() : GHOST_System()
  { /* nop */
  }
  ~GHOST_SystemNULL()
  { /* nop */
  }
  bool processEvents(bool waitForEvent)
  {
    return false;
  }
  int toggleConsole(int action)
  {
    return 0;
  }
  GHOST_TSuccess getModifierKeys(GHOST_ModifierKeys &keys) const
  {
    return GHOST_kSuccess;
  }
  GHOST_TSuccess getButtons(GHOST_Buttons &buttons) const
  {
    return GHOST_kSuccess;
  }
  GHOST_TUns8 *getClipboard(bool selection) const
  {
    return NULL;
  }
  void putClipboard(GHOST_TInt8 *buffer, bool selection) const
  { /* nop */
  }
  GHOST_TUns64 getMilliSeconds() const
  {
    return 0;
  }
  GHOST_TUns8 getNumDisplays() const
  {
    return GHOST_TUns8(1);
  }
  GHOST_TSuccess getCursorPosition(GHOST_TInt32 &x, GHOST_TInt32 &y) const
  {
    return GHOST_kFailure;
  }
  GHOST_TSuccess setCursorPosition(GHOST_TInt32 x, GHOST_TInt32 y)
  {
    return GHOST_kFailure;
  }
  void getMainDisplayDimensions(GHOST_TUns32 &width, GHOST_TUns32 &height) const
  { /* nop */
  }
  void getAllDisplayDimensions(GHOST_TUns32 &width, GHOST_TUns32 &height) const
  { /* nop */
  }
  GHOST_IContext *createOffscreenContext(GHOST_GLSettings glSettings)
  {
    return NULL;
  }
  GHOST_TSuccess disposeContext(GHOST_IContext *context)
  {
    return GHOST_kFailure;
  }

  GHOST_TSuccess init()
  {
    GHOST_TSuccess success = GHOST_System::init();

    if (success) {
      m_displayManager = new GHOST_DisplayManagerNULL(this);

      if (m_displayManager) {
        return GHOST_kSuccess;
      }
    }

    return GHOST_kFailure;
  }

  GHOST_IWindow *createWindow(const char *title,
                              GHOST_TInt32 left,
                              GHOST_TInt32 top,
                              GHOST_TUns32 width,
                              GHOST_TUns32 height,
                              GHOST_TWindowState state,
                              GHOST_TDrawingContextType type,
                              GHOST_GLSettings glSettings,
                              const bool exclusive,
                              const bool is_dialog,
                              const GHOST_IWindow *parentWindow)
  {
    return new GHOST_WindowNULL(this,
                                title,
                                left,
                                top,
                                width,
                                height,
                                state,
                                parentWindow,
                                type,
                                ((glSettings.flags & GHOST_glStereoVisual) != 0));
  }
};
