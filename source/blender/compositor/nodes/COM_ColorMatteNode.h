/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief ColorMatteNode
 * \ingroup Node
 */
class ColorMatteNode : public Node {
 public:
  ColorMatteNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
