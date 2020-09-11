/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief PixelateNode
 * \ingroup Node
 */
class PixelateNode : public Node {
 public:
  PixelateNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
