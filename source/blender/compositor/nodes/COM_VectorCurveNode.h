/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief VectorCurveNode
 * \ingroup Node
 */
class VectorCurveNode : public Node {
 public:
  VectorCurveNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
