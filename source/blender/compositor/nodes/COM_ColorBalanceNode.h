/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief ColorBalanceNode
 * \ingroup Node
 */
class ColorBalanceNode : public Node {
 public:
  ColorBalanceNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
