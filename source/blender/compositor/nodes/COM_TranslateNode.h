/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief TranslateNode
 * \ingroup Node
 */
class TranslateNode : public Node {
 public:
  TranslateNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
