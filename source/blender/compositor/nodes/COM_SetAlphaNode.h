/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief SetAlphaNode
 * \ingroup Node
 */
class SetAlphaNode : public Node {
 public:
  SetAlphaNode(bNode *editorNode) : Node(editorNode)
  {
  }
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
