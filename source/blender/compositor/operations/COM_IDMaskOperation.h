/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class IDMaskOperation : public NodeOperation {
 private:
  float m_objectIndex;

 public:
  IDMaskOperation();

  void *initializeTileData(rcti *rect);
  void executePixel(float output[4], int x, int y, void *data);

  void setObjectIndex(float objectIndex)
  {
    this->m_objectIndex = objectIndex;
  }
};
