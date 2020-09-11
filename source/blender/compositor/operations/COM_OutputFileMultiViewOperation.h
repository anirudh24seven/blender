/** Copyright 2015, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "COM_OutputFileOperation.h"

#include "BLI_path_util.h"
#include "BLI_rect.h"

#include "DNA_color_types.h"

#include "intern/openexr/openexr_multi.h"

class OutputOpenExrSingleLayerMultiViewOperation : public OutputSingleLayerOperation {
 private:
 public:
  OutputOpenExrSingleLayerMultiViewOperation(const RenderData *rd,
                                             const bNodeTree *tree,
                                             DataType datatype,
                                             ImageFormatData *format,
                                             const char *path,
                                             const ColorManagedViewSettings *viewSettings,
                                             const ColorManagedDisplaySettings *displaySettings,
                                             const char *viewName);

  void *get_handle(const char *filename);
  void deinitExecution();
};

/* Writes inputs into OpenEXR multilayer channels. */
class OutputOpenExrMultiLayerMultiViewOperation : public OutputOpenExrMultiLayerOperation {
 private:
 public:
  OutputOpenExrMultiLayerMultiViewOperation(const RenderData *rd,
                                            const bNodeTree *tree,
                                            const char *path,
                                            char exr_codec,
                                            bool exr_half_float,
                                            const char *viewName);

  void *get_handle(const char *filename);
  void deinitExecution();
};

class OutputStereoOperation : public OutputSingleLayerOperation {
 private:
  char m_name[FILE_MAX];
  size_t m_channels;

 public:
  OutputStereoOperation(const RenderData *rd,
                        const bNodeTree *tree,
                        DataType datatype,
                        struct ImageFormatData *format,
                        const char *path,
                        const char *name,
                        const ColorManagedViewSettings *viewSettings,
                        const ColorManagedDisplaySettings *displaySettings,
                        const char *viewName);
  void *get_handle(const char *filename);
  void deinitExecution();
};
