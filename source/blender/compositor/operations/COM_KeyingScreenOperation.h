/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include <string.h>

#include "COM_NodeOperation.h"

#include "DNA_movieclip_types.h"

#include "BLI_listbase.h"
#include "BLI_string.h"

#include "BLI_voronoi_2d.h"

/**
 * Class with implementation of green screen gradient rasterization
 */
class KeyingScreenOperation : public NodeOperation {
 protected:
  typedef struct TriangulationData {
    VoronoiTriangulationPoint *triangulated_points;
    int (*triangles)[3];
    int triangulated_points_total, triangles_total;
    rcti *triangles_AABB;
  } TriangulationData;

  typedef struct TileData {
    int *triangles;
    int triangles_total;
  } TileData;

  MovieClip *m_movieClip;
  int m_framenumber;
  TriangulationData *m_cachedTriangulation;
  char m_trackingObject[64];

  /**
   * Determine the output resolution. The resolution is retrieved from the Renderer
   */
  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);

  TriangulationData *buildVoronoiTriangulation();

 public:
  KeyingScreenOperation();

  void initExecution();
  void deinitExecution();

  void *initializeTileData(rcti *rect);
  void deinitializeTileData(rcti *rect, void *data);

  void setMovieClip(MovieClip *clip)
  {
    this->m_movieClip = clip;
  }
  void setTrackingObject(const char *object)
  {
    BLI_strncpy(this->m_trackingObject, object, sizeof(this->m_trackingObject));
  }
  void setFramenumber(int framenumber)
  {
    this->m_framenumber = framenumber;
  }

  void executePixel(float output[4], int x, int y, void *data);
};
