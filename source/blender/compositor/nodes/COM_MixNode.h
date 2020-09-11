/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"
#include "DNA_node_types.h"
/**
 * \brief MixNode
 * \ingroup Node
 */
class MixNode : public Node {
 public:
  MixNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
