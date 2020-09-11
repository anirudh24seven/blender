/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "BLI_listbase.h"
#include "COM_NodeOperation.h"
#include "DNA_texture_types.h"
#include "MEM_guardedalloc.h"

#include "RE_pipeline.h"
#include "RE_render_ext.h"
#include "RE_shader_ext.h"

/**
 * Base class for all renderlayeroperations
 *
 * \todo: rename to operation.
 */
class TextureBaseOperation : public NodeOperation {
 private:
  Tex *m_texture;
  const RenderData *m_rd;
  SocketReader *m_inputSize;
  SocketReader *m_inputOffset;
  struct ImagePool *m_pool;
  bool m_sceneColorManage;

 protected:
  /**
   * Determine the output resolution. The resolution is retrieved from the Renderer
   */
  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);

  /**
   * Constructor
   */
  TextureBaseOperation();

 public:
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  void setTexture(Tex *texture)
  {
    this->m_texture = texture;
  }
  void initExecution();
  void deinitExecution();
  void setRenderData(const RenderData *rd)
  {
    this->m_rd = rd;
  }
  void setSceneColorManage(bool sceneColorManage)
  {
    this->m_sceneColorManage = sceneColorManage;
  }
};

class TextureOperation : public TextureBaseOperation {
 public:
  TextureOperation();
};
class TextureAlphaOperation : public TextureBaseOperation {
 public:
  TextureAlphaOperation();
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};
