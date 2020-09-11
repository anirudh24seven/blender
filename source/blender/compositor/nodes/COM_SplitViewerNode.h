/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"
#include "DNA_node_types.h"
/**
 * \brief SplitViewerNode
 * \ingroup Node
 */
class SplitViewerNode : public Node {
 public:
  SplitViewerNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
