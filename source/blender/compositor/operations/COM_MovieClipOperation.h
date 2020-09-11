/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "BLI_listbase.h"
#include "COM_NodeOperation.h"
#include "DNA_movieclip_types.h"
#include "IMB_imbuf_types.h"

/**
 * Base class for movie clip
 */
class MovieClipBaseOperation : public NodeOperation {
 protected:
  MovieClip *m_movieClip;
  MovieClipUser *m_movieClipUser;
  ImBuf *m_movieClipBuffer;
  int m_movieClipheight;
  int m_movieClipwidth;
  int m_framenumber;
  bool m_cacheFrame;

  /**
   * Determine the output resolution. The resolution is retrieved from the Renderer
   */
  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);

 public:
  MovieClipBaseOperation();

  void initExecution();
  void deinitExecution();
  void setMovieClip(MovieClip *image)
  {
    this->m_movieClip = image;
  }
  void setMovieClipUser(MovieClipUser *imageuser)
  {
    this->m_movieClipUser = imageuser;
  }
  void setCacheFrame(bool value)
  {
    this->m_cacheFrame = value;
  }

  void setFramenumber(int framenumber)
  {
    this->m_framenumber = framenumber;
  }
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};

class MovieClipOperation : public MovieClipBaseOperation {
 public:
  MovieClipOperation();
};

class MovieClipAlphaOperation : public MovieClipBaseOperation {
 public:
  MovieClipAlphaOperation();
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};
