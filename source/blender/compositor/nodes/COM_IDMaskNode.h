/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief IDMaskNode
 * \ingroup Node
 */
class IDMaskNode : public Node {
 public:
  IDMaskNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
