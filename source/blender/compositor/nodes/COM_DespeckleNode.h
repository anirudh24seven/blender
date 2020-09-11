/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief DespeckleNode
 * \ingroup Node
 */
class DespeckleNode : public Node {
 public:
  DespeckleNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
