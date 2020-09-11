/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief BilateralBlurNode
 * \ingroup Node
 */
class BilateralBlurNode : public Node {
 public:
  BilateralBlurNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
