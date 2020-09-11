/** Copyright 2013, Blender Foundation.
 */

#pragma once

#include <string.h>

#include "COM_PlaneDistortCommonOperation.h"

#include "DNA_movieclip_types.h"
#include "DNA_tracking_types.h"

#include "BLI_listbase.h"
#include "BLI_string.h"

class PlaneTrackCommon {
 protected:
  MovieClip *m_movieClip;
  int m_framenumber;
  char m_trackingObjectName[64];
  char m_planeTrackName[64];

  /* note: this class is not an operation itself (to prevent virtual inheritance issues)
   * implementation classes must make wrappers to use these methods, see below.
   */
  void readCornersFromTrack(float corners[4][2], float frame);
  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);

 public:
  PlaneTrackCommon();

  void setMovieClip(MovieClip *clip)
  {
    this->m_movieClip = clip;
  }
  void setTrackingObject(char *object)
  {
    BLI_strncpy(this->m_trackingObjectName, object, sizeof(this->m_trackingObjectName));
  }
  void setPlaneTrackName(char *plane_track)
  {
    BLI_strncpy(this->m_planeTrackName, plane_track, sizeof(this->m_planeTrackName));
  }
  void setFramenumber(int framenumber)
  {
    this->m_framenumber = framenumber;
  }
};

class PlaneTrackMaskOperation : public PlaneDistortMaskOperation, public PlaneTrackCommon {
 public:
  PlaneTrackMaskOperation() : PlaneDistortMaskOperation(), PlaneTrackCommon()
  {
  }

  void initExecution();

  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2])
  {
    PlaneTrackCommon::determineResolution(resolution, preferredResolution);

    unsigned int temp[2];
    NodeOperation::determineResolution(temp, resolution);
  }
};

class PlaneTrackWarpImageOperation : public PlaneDistortWarpImageOperation,
                                     public PlaneTrackCommon {
 public:
  PlaneTrackWarpImageOperation() : PlaneDistortWarpImageOperation(), PlaneTrackCommon()
  {
  }

  void initExecution();

  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2])
  {
    PlaneTrackCommon::determineResolution(resolution, preferredResolution);
    unsigned int temp[2];
    NodeOperation::determineResolution(temp, resolution);
  }
};
