#pragma once

#include <string.h>

#include "COM_PlaneDistortCommonOperation.h"

#include "DNA_movieclip_types.h"
#include "DNA_tracking_types.h"

#include "BLI_listbase.h"
#include "BLI_string.h"

class PlaneCornerPinMaskOperation : public PlaneDistortMaskOperation {
 private:
  bool m_corners_ready;

 public:
  PlaneCornerPinMaskOperation();

  void initExecution();
  void deinitExecution();

  void *initializeTileData(rcti *rect);

  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);
};

class PlaneCornerPinWarpImageOperation : public PlaneDistortWarpImageOperation {
 private:
  bool m_corners_ready;

 public:
  PlaneCornerPinWarpImageOperation();

  void initExecution();
  void deinitExecution();

  void *initializeTileData(rcti *rect);

  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
};
