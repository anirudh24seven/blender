/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief DistanceMatteNode
 * \ingroup Node
 */
class DistanceMatteNode : public Node {
 public:
  DistanceMatteNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
