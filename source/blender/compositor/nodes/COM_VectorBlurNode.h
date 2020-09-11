/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief VectorBlurNode
 * \ingroup Node
 */
class VectorBlurNode : public Node {
 public:
  VectorBlurNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
