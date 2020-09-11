/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief BoxMaskNode
 * \ingroup Node
 */
class BoxMaskNode : public Node {
 public:
  BoxMaskNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
