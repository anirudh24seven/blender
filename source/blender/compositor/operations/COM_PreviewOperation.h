/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "BKE_global.h"
#include "BLI_rect.h"
#include "COM_NodeOperation.h"
#include "DNA_color_types.h"
#include "DNA_image_types.h"

class PreviewOperation : public NodeOperation {
 protected:
  unsigned char *m_outputBuffer;

  /**
   * \brief holds reference to the SDNA bNode, where this nodes will render the preview image for
   */
  bNodePreview *m_preview;
  SocketReader *m_input;
  float m_divider;

  const ColorManagedViewSettings *m_viewSettings;
  const ColorManagedDisplaySettings *m_displaySettings;

 public:
  PreviewOperation(const ColorManagedViewSettings *viewSettings,
                   const ColorManagedDisplaySettings *displaySettings);
  void verifyPreview(bNodeInstanceHash *previews, bNodeInstanceKey key);

  bool isOutputOperation(bool /*rendering*/) const
  {
    return !G.background;
  }
  void initExecution();
  void deinitExecution();
  CompositorPriority getRenderPriority() const;

  void executeRegion(rcti *rect, unsigned int tileNumber);
  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
  bool isPreviewOperation() const
  {
    return true;
  }
};
