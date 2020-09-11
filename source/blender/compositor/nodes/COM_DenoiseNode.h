#pragma once

#include "COM_Node.h"

/**
 * \brief DenoiseNode
 * \ingroup Node
 */
class DenoiseNode : public Node {
 public:
  DenoiseNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
