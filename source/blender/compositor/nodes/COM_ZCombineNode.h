/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief ZCombineNode
 * \ingroup Node
 */
class ZCombineNode : public Node {
 public:
  ZCombineNode(bNode *editorNode) : Node(editorNode)
  {
  }
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
