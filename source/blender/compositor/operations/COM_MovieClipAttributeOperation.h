/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "DNA_movieclip_types.h"

typedef enum MovieClipAttribute {
  MCA_SCALE,
  MCA_X,
  MCA_Y,
  MCA_ANGLE,
} MovieClipAttribute;
/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class MovieClipAttributeOperation : public NodeOperation {
 private:
  MovieClip *m_clip;
  float m_value;
  int m_framenumber;
  bool m_invert;
  MovieClipAttribute m_attribute;

 public:
  /**
   * Default constructor
   */
  MovieClipAttributeOperation();

  void initExecution();

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);

  void setMovieClip(MovieClip *clip)
  {
    this->m_clip = clip;
  }
  void setFramenumber(int framenumber)
  {
    this->m_framenumber = framenumber;
  }
  void setAttribute(MovieClipAttribute attribute)
  {
    this->m_attribute = attribute;
  }
  void setInvert(bool invert)
  {
    this->m_invert = invert;
  }
};
