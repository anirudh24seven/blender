/** Copyright 2011, Blender Foundation.
 */

#include "COM_ChunkOrderHotspot.h"
#include <math.h>

ChunkOrderHotspot::ChunkOrderHotspot(int x, int y, float addition)
{
  this->m_x = x;
  this->m_y = y;
  this->m_addition = addition;
}

double ChunkOrderHotspot::determineDistance(int x, int y)
{
  int dx = x - this->m_x;
  int dy = y - this->m_y;
  double result = sqrt((double)(dx * dx + dy * dy));
  result += (double)this->m_addition;
  return result;
}
