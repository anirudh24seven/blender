#pragma once

#include "COM_Node.h"

/**
 * \brief SunBeamsNode
 * \ingroup Node
 */
class SunBeamsNode : public Node {
 public:
  SunBeamsNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
