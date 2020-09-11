/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief MathNode
 * \ingroup Node
 */
class MathNode : public Node {
 public:
  MathNode(bNode *editorNode) : Node(editorNode)
  {
  }
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
