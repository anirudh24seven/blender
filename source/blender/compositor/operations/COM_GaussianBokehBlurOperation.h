/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_BlurBaseOperation.h"
#include "COM_NodeOperation.h"
#include "COM_QualityStepHelper.h"

class GaussianBokehBlurOperation : public BlurBaseOperation {
 private:
  float *m_gausstab;
  int m_radx, m_rady;
  void updateGauss();

 public:
  GaussianBokehBlurOperation();
  void initExecution();
  void *initializeTileData(rcti *rect);
  /**
   * the inner loop of this program
   */
  void executePixel(float output[4], int x, int y, void *data);

  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
};

class GaussianBlurReferenceOperation : public BlurBaseOperation {
 private:
  float **m_maintabs;

  void updateGauss();
  int m_filtersizex;
  int m_filtersizey;
  float m_radx;
  float m_rady;

 public:
  GaussianBlurReferenceOperation();
  void initExecution();
  void *initializeTileData(rcti *rect);
  /**
   * the inner loop of this program
   */
  void executePixel(float output[4], int x, int y, void *data);

  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
};
