/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief EllipseMaskNode
 * \ingroup Node
 */
class EllipseMaskNode : public Node {
 public:
  EllipseMaskNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
