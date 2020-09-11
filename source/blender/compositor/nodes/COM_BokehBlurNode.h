/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief BokehBlurNode
 * \ingroup Node
 */
class BokehBlurNode : public Node {
 public:
  BokehBlurNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
