/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class ConvertColorProfileOperation : public NodeOperation {
 private:
  /**
   * Cached reference to the inputProgram
   */
  SocketReader *m_inputOperation;

  /**
   * \brief color profile where to convert from
   */
  int m_fromProfile;

  /**
   * \brief color profile where to convert to
   */
  int m_toProfile;

  /**
   * \brief is color predivided
   */
  bool m_predivided;

 public:
  /**
   * Default constructor
   */
  ConvertColorProfileOperation();

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

  void setFromColorProfile(int colorProfile)
  {
    this->m_fromProfile = colorProfile;
  }
  void setToColorProfile(int colorProfile)
  {
    this->m_toProfile = colorProfile;
  }
  void setPredivided(bool predivided)
  {
    this->m_predivided = predivided;
  }
};
