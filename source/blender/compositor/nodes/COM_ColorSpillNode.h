/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief ColorSpillNode
 * \ingroup Node
 */
class ColorSpillNode : public Node {
 public:
  ColorSpillNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
