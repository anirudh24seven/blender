/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief TonemapNode
 * \ingroup Node
 */
class TonemapNode : public Node {
 public:
  TonemapNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
