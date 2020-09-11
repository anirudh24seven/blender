/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"
#include "DNA_node_types.h"

/**
 * \brief MaskNode
 * \ingroup Node
 */
class MaskNode : public Node {
 public:
  MaskNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
