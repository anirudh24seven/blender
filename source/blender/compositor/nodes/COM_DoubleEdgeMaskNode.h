/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief DoubleEdgeMaskNode
 * \ingroup Node
 */
class DoubleEdgeMaskNode : public Node {
 public:
  DoubleEdgeMaskNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
