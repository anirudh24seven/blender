/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_ChunkOrderHotspot.h"
class ChunkOrder {
 private:
  unsigned int m_number;
  int m_x;
  int m_y;
  double m_distance;

 public:
  ChunkOrder();
  void determineDistance(ChunkOrderHotspot **hotspots, unsigned int numberOfHotspots);
  friend bool operator<(const ChunkOrder &a, const ChunkOrder &b);

  void setChunkNumber(unsigned int chunknumber)
  {
    this->m_number = chunknumber;
  }
  void setX(int x)
  {
    this->m_x = x;
  }
  void setY(int y)
  {
    this->m_y = y;
  }
  unsigned int getChunkNumber()
  {
    return this->m_number;
  }
  double getDistance()
  {
    return this->m_distance;
  }
};
