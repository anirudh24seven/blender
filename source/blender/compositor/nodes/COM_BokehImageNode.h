/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief BokehImageNode
 * \ingroup Node
 */
class BokehImageNode : public Node {
 public:
  BokehImageNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
