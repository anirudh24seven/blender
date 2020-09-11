/** Copyright 2011, Blender Foundation.
 */

#include "COM_DistanceYCCMatteOperation.h"
#include "BLI_math.h"

DistanceYCCMatteOperation::DistanceYCCMatteOperation() : DistanceRGBMatteOperation()
{
  /* pass */
}

float DistanceYCCMatteOperation::calculateDistance(float key[4], float image[4])
{
  /* only measure the second 2 values */
  return len_v2v2(key + 1, image + 1);
}
