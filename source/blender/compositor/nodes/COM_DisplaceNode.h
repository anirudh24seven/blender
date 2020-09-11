/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief DisplaceNode
 * \ingroup Node
 */
class DisplaceNode : public Node {
 public:
  DisplaceNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
