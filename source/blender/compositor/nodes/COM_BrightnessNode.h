/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief BrightnessNode
 * \ingroup Node
 */
class BrightnessNode : public Node {
 public:
  BrightnessNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
