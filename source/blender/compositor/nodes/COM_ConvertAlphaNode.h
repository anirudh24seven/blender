/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief ConvertAlphaNode
 * \ingroup Node
 */
class ConvertAlphaNode : public Node {
 public:
  ConvertAlphaNode(bNode *editorNode) : Node(editorNode)
  {
  }
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
