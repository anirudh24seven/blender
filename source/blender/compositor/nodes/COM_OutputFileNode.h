/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"
#include "DNA_node_types.h"

/**
 * \brief OutputFileNode
 * \ingroup Node
 */
class OutputFileNode : public Node {
 public:
  OutputFileNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
