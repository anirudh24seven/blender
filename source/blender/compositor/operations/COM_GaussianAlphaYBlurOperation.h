/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_BlurBaseOperation.h"
#include "COM_NodeOperation.h"

class GaussianAlphaYBlurOperation : public BlurBaseOperation {
 private:
  float *m_gausstab;
  float *m_distbuf_inv;
  bool m_do_subtract;
  int m_falloff;
  int m_filtersize;
  void updateGauss();

 public:
  GaussianAlphaYBlurOperation();

  /**
   * the inner loop of this program
   */
  void executePixel(float output[4], int x, int y, void *data);

  /**
   * \brief initialize the execution
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

  /**
   * Set subtract for Dilate/Erode functionality
   */
  void setSubtract(bool subtract)
  {
    this->m_do_subtract = subtract;
  }
  void setFalloff(int falloff)
  {
    this->m_falloff = falloff;
  }
};
