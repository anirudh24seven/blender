/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief NormalizeNode
 * \ingroup Node
 */
class NormalizeNode : public Node {
 public:
  NormalizeNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
