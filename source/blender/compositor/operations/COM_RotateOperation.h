/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class RotateOperation : public NodeOperation {
 private:
  SocketReader *m_imageSocket;
  SocketReader *m_degreeSocket;
  float m_centerX;
  float m_centerY;
  float m_cosine;
  float m_sine;
  bool m_doDegree2RadConversion;
  bool m_isDegreeSet;

 public:
  RotateOperation();
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
  void initExecution();
  void deinitExecution();
  void setDoDegree2RadConversion(bool abool)
  {
    this->m_doDegree2RadConversion = abool;
  }

  void ensureDegree();
};
