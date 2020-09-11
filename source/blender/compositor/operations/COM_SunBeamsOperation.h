#pragma once

#include "COM_NodeOperation.h"

class SunBeamsOperation : public NodeOperation {
 public:
  SunBeamsOperation();

  void executePixel(float output[4], int x, int y, void *data);

  void initExecution();

  void *initializeTileData(rcti *rect);

  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);

  void setData(const NodeSunBeams &data)
  {
    m_data = data;
  }

 private:
  NodeSunBeams m_data;

  float m_source_px[2];
  float m_ray_length_px;
};
