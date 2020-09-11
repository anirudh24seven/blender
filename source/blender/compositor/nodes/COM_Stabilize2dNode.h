/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"
#include "DNA_node_types.h"

/**
 * \brief Stabilize2dNode
 * \ingroup Node
 */
class Stabilize2dNode : public Node {
 public:
  Stabilize2dNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
