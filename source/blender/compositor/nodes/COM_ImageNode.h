/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"
#include "COM_defines.h"
#include "DNA_image_types.h"
#include "DNA_node_types.h"

#include "RE_engine.h"

/**
 * \brief ImageNode
 * \ingroup Node
 */
class ImageNode : public Node {
 private:
  NodeOperation *doMultilayerCheck(NodeConverter &converter,
                                   RenderLayer *rl,
                                   Image *image,
                                   ImageUser *user,
                                   int framenumber,
                                   int outputsocketIndex,
                                   int passindex,
                                   int view,
                                   DataType datatype) const;

 public:
  ImageNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
