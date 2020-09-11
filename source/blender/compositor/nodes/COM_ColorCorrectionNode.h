/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief ColorCorrectionNode
 * \ingroup Node
 */
class ColorCorrectionNode : public Node {
 public:
  ColorCorrectionNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
