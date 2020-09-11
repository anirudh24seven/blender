/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief MapUVNode
 * \ingroup Node
 */
class MapUVNode : public Node {
 public:
  MapUVNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
