/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_FastGaussianBlurOperation.h"
#include "COM_NodeOperation.h"
#include "DNA_object_types.h"
/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class ConvertDepthToRadiusOperation : public NodeOperation {
 private:
  /**
   * Cached reference to the inputProgram
   */
  SocketReader *m_inputOperation;
  float m_fStop;
  float m_aspect;
  float m_maxRadius;
  float m_inverseFocalDistance;
  float m_aperture;
  float m_cam_lens;
  float m_dof_sp;
  Object *m_cameraObject;

  FastGaussianBlurValueOperation *m_blurPostOperation;

 public:
  /**
   * Default constructor
   */
  ConvertDepthToRadiusOperation();

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  /**
   * Initialize the execution
   */
  void initExecution();

  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  void setfStop(float fStop)
  {
    this->m_fStop = fStop;
  }
  void setMaxRadius(float maxRadius)
  {
    this->m_maxRadius = maxRadius;
  }
  void setCameraObject(Object *camera)
  {
    this->m_cameraObject = camera;
  }
  float determineFocalDistance();
  void setPostBlur(FastGaussianBlurValueOperation *operation)
  {
    this->m_blurPostOperation = operation;
  }
};
