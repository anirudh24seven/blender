/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

/**
 * Class with implementation of black/white clipping for keying node
 */
class KeyingClipOperation : public NodeOperation {
 protected:
  float m_clipBlack;
  float m_clipWhite;

  int m_kernelRadius;
  float m_kernelTolerance;

  bool m_isEdgeMatte;

 public:
  KeyingClipOperation();

  void setClipBlack(float value)
  {
    this->m_clipBlack = value;
  }
  void setClipWhite(float value)
  {
    this->m_clipWhite = value;
  }

  void setKernelRadius(int value)
  {
    this->m_kernelRadius = value;
  }
  void setKernelTolerance(float value)
  {
    this->m_kernelTolerance = value;
  }

  void setIsEdgeMatte(bool value)
  {
    this->m_isEdgeMatte = value;
  }

  void *initializeTileData(rcti *rect);

  void executePixel(float output[4], int x, int y, void *data);

  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
};
