/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"
#include "DNA_node_types.h"
/**
 * \brief MapRangeNode
 * \ingroup Node
 */
class MapRangeNode : public Node {
 public:
  MapRangeNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
