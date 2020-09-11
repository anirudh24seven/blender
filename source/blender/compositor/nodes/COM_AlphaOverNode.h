/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief AlphaOverNode
 * \ingroup Node
 */
class AlphaOverNode : public Node {
 public:
  AlphaOverNode(bNode *editorNode) : Node(editorNode)
  {
  }
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
