/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief HueSaturationValueCorrectNode
 * \ingroup Node
 */
class HueSaturationValueCorrectNode : public Node {
 public:
  HueSaturationValueCorrectNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
