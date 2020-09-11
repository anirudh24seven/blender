/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"
#include "DNA_node_types.h"

/**
 * \brief TrackPositionNode
 * \ingroup Node
 */
class TrackPositionNode : public Node {
 public:
  TrackPositionNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
