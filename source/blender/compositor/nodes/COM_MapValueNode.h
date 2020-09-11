/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"
#include "DNA_node_types.h"
/**
 * \brief MapValueNode
 * \ingroup Node
 */
class MapValueNode : public Node {
 public:
  MapValueNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
