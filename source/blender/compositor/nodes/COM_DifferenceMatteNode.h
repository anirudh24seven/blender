/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief DifferenceMatteNode
 * \ingroup Node
 */
class DifferenceMatteNode : public Node {
 public:
  DifferenceMatteNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
