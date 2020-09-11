/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief ViewLevelsNode
 * \ingroup Node
 */
class ViewLevelsNode : public Node {
 public:
  ViewLevelsNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
