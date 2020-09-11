/** Copyright 2011, Blender Foundation.
 */

#pragma once

#ifdef WITH_CXX_GUARDEDALLOC
#  include "MEM_guardedalloc.h"
#endif

class ChunkOrderHotspot {
 private:
  int m_x;
  int m_y;
  float m_addition;

 public:
  ChunkOrderHotspot(int x, int y, float addition);
  double determineDistance(int x, int y);

#ifdef WITH_CXX_GUARDEDALLOC
  MEM_CXX_CLASS_ALLOC_FUNCS("COM:ChunkOrderHotspot")
#endif
};
