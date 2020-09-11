/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class DoubleEdgeMaskOperation : public NodeOperation {
 private:
  /**
   * Cached reference to the inputProgram
   */
  SocketReader *m_inputOuterMask;
  SocketReader *m_inputInnerMask;
  bool m_adjecentOnly;
  bool m_keepInside;
  float *m_cachedInstance;

 public:
  DoubleEdgeMaskOperation();

  void doDoubleEdgeMask(float *imask, float *omask, float *res);
  /**
   * the inner loop of this program
   */
  void executePixel(float output[4], int x, int y, void *data);

  /**
   * Initialize the execution
   */
  void initExecution();

  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  void *initializeTileData(rcti *rect);

  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);

  void setAdjecentOnly(bool adjecentOnly)
  {
    this->m_adjecentOnly = adjecentOnly;
  }
  void setKeepInside(bool keepInside)
  {
    this->m_keepInside = keepInside;
  }
};
