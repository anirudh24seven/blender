/** Copyright 2011, Blender Foundation.
 */

#include "COM_ChunkOrder.h"
#include "BLI_math.h"

ChunkOrder::ChunkOrder()
{
  this->m_distance = 0.0;
  this->m_number = 0;
  this->m_x = 0;
  this->m_y = 0;
}

void ChunkOrder::determineDistance(ChunkOrderHotspot **hotspots, unsigned int numberOfHotspots)
{
  unsigned int index;
  double distance = FLT_MAX;
  for (index = 0; index < numberOfHotspots; index++) {
    ChunkOrderHotspot *hotspot = hotspots[index];
    double ndistance = hotspot->determineDistance(this->m_x, this->m_y);
    if (ndistance < distance) {
      distance = ndistance;
    }
  }
  this->m_distance = distance;
}

bool operator<(const ChunkOrder &a, const ChunkOrder &b)
{
  return a.m_distance < b.m_distance;
}
