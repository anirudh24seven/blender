#pragma once

#include "COM_Node.h"

#include "DNA_node_types.h"

/**
 * \brief CornerPinNode
 * \ingroup Node
 */
class CornerPinNode : public Node {
 public:
  CornerPinNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
