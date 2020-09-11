#pragma once

#include "COM_Node.h"

/**
 * \brief CryptomatteNode
 * \ingroup Node
 */
class CryptomatteNode : public Node {
 public:
  CryptomatteNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
