/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_ImageOperation.h"

class MultilayerBaseOperation : public BaseImageOperation {
 private:
  int m_passId;
  int m_view;
  RenderLayer *m_renderlayer;

 protected:
  ImBuf *getImBuf();

 public:
  /**
   * Constructor
   */
  MultilayerBaseOperation(int passindex, int view);
  void setRenderLayer(RenderLayer *renderlayer)
  {
    this->m_renderlayer = renderlayer;
  }
};

class MultilayerColorOperation : public MultilayerBaseOperation {
 public:
  MultilayerColorOperation(int passindex, int view) : MultilayerBaseOperation(passindex, view)
  {
    this->addOutputSocket(COM_DT_COLOR);
  }
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};

class MultilayerValueOperation : public MultilayerBaseOperation {
 public:
  MultilayerValueOperation(int passindex, int view) : MultilayerBaseOperation(passindex, view)
  {
    this->addOutputSocket(COM_DT_VALUE);
  }
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};

class MultilayerVectorOperation : public MultilayerBaseOperation {
 public:
  MultilayerVectorOperation(int passindex, int view) : MultilayerBaseOperation(passindex, view)
  {
    this->addOutputSocket(COM_DT_VECTOR);
  }
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};
