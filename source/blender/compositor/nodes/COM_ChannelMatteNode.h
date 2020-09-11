/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief ChannelMatteNode
 * \ingroup Node
 */
class ChannelMatteNode : public Node {
 public:
  ChannelMatteNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
