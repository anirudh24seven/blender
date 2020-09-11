/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class TranslateOperation : public NodeOperation {
 private:
  SocketReader *m_inputOperation;
  SocketReader *m_inputXOperation;
  SocketReader *m_inputYOperation;
  float m_deltaX;
  float m_deltaY;
  bool m_isDeltaSet;
  float m_factorX;
  float m_factorY;

 public:
  TranslateOperation();
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  void initExecution();
  void deinitExecution();

  float getDeltaX()
  {
    return this->m_deltaX * this->m_factorX;
  }
  float getDeltaY()
  {
    return this->m_deltaY * this->m_factorY;
  }

  inline void ensureDelta()
  {
    if (!this->m_isDeltaSet) {
      float tempDelta[4];
      this->m_inputXOperation->readSampled(tempDelta, 0, 0, COM_PS_NEAREST);
      this->m_deltaX = tempDelta[0];
      this->m_inputYOperation->readSampled(tempDelta, 0, 0, COM_PS_NEAREST);
      this->m_deltaY = tempDelta[0];
      this->m_isDeltaSet = true;
    }
  }

  void setFactorXY(float factorX, float factorY);
};
