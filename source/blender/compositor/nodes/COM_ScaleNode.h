/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief ScaleNode
 * \ingroup Node
 */
class ScaleNode : public Node {
 public:
  ScaleNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
