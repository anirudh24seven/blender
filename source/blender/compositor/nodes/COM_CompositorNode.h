/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"
#include "DNA_node_types.h"
/**
 * \brief CompositorNode
 * \ingroup Node
 */
class CompositorNode : public Node {
 public:
  CompositorNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
