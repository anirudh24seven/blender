/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"
#include "DNA_node_types.h"

/**
 * \brief KeyingScreenNode
 * \ingroup Node
 */
class KeyingScreenNode : public Node {
 public:
  KeyingScreenNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
