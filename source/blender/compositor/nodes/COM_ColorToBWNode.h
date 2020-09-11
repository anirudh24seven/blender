/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"
#include "DNA_node_types.h"
/**
 * \brief ColorToBWNode
 * \ingroup Node
 */
class ColorToBWNode : public Node {
 public:
  ColorToBWNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
