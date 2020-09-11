/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief ColorCurveNode
 * \ingroup Node
 */
class ColorCurveNode : public Node {
 public:
  ColorCurveNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
