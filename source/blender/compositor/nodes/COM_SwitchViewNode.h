/** Copyright 2015, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"
#include "COM_NodeOperation.h"
#include "DNA_node_types.h"
/**
 * \brief SwitchViewNode
 * \ingroup Node
 */
class SwitchViewNode : public Node {
 public:
  SwitchViewNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
