/** \file
 * \ingroup GHOST
 * Declaration of GHOST_WindowSDL class.
 */

#pragma once

#include "GHOST_SystemSDL.h"
#include "GHOST_Window.h"

#include <map>

extern "C" {
#include "SDL.h"
}

#if !SDL_VERSION_ATLEAST(2, 0, 0)
#  error "SDL 2.0 or newer is needed to build with Ghost"
#endif

class GHOST_SystemSDL;

class GHOST_WindowSDL : public GHOST_Window {
 private:
  GHOST_SystemSDL *m_system;
  bool m_valid_setup;
  bool m_invalid_window;

  SDL_Window *m_sdl_win;
  SDL_Cursor *m_sdl_custom_cursor;

 public:
  GHOST_WindowSDL(GHOST_SystemSDL *system,
                  const char *title,
                  GHOST_TInt32 left,
                  GHOST_TInt32 top,
                  GHOST_TUns32 width,
                  GHOST_TUns32 height,
                  GHOST_TWindowState state,
                  GHOST_TDrawingContextType type = GHOST_kDrawingContextTypeNone,
                  const bool stereoVisual = false,
                  const bool exclusive = false,
                  const GHOST_IWindow *parentWindow = NULL);

  ~GHOST_WindowSDL();

  /* SDL specific */
  SDL_Window *getSDLWindow()
  {
    return m_sdl_win;
  }

  GHOST_TSuccess invalidate(void);

  /**
   * called by the X11 system implementation when expose events
   * for the window have been pushed onto the GHOST queue
   */

  void validate()
  {
    m_invalid_window = false;
  }

  bool getValid() const;

  void getWindowBounds(GHOST_Rect &bounds) const;
  void getClientBounds(GHOST_Rect &bounds) const;

 protected:
  /**
   * \param type  The type of rendering context create.
   * \return Indication of success.
   */
  GHOST_Context *newDrawingContext(GHOST_TDrawingContextType type);

  GHOST_TSuccess setWindowCursorGrab(GHOST_TGrabCursorMode mode);

  GHOST_TSuccess setWindowCursorShape(GHOST_TStandardCursor shape);
  GHOST_TSuccess hasCursorShape(GHOST_TStandardCursor shape);

  GHOST_TSuccess setWindowCustomCursorShape(GHOST_TUns8 *bitmap,
                                            GHOST_TUns8 *mask,
                                            int sizex,
                                            int sizey,
                                            int hotX,
                                            int hotY,
                                            bool canInvertColor);

  GHOST_TSuccess setWindowCursorVisibility(bool visible);

  void setTitle(const char *title);

  std::string getTitle() const;

  GHOST_TSuccess setClientWidth(GHOST_TUns32 width);

  GHOST_TSuccess setClientHeight(GHOST_TUns32 height);

  GHOST_TSuccess setClientSize(GHOST_TUns32 width, GHOST_TUns32 height);

  void screenToClient(GHOST_TInt32 inX,
                      GHOST_TInt32 inY,
                      GHOST_TInt32 &outX,
                      GHOST_TInt32 &outY) const;

  void clientToScreen(GHOST_TInt32 inX,
                      GHOST_TInt32 inY,
                      GHOST_TInt32 &outX,
                      GHOST_TInt32 &outY) const;

  GHOST_TSuccess setState(GHOST_TWindowState state);

  GHOST_TWindowState getState() const;

  GHOST_TSuccess setOrder(GHOST_TWindowOrder order)
  {
    // TODO
    return GHOST_kSuccess;
  }

  // TODO
  GHOST_TSuccess beginFullScreen() const
  {
    return GHOST_kFailure;
  }

  GHOST_TSuccess endFullScreen() const
  {
    return GHOST_kFailure;
  }

  GHOST_TUns16 getDPIHint();
};
