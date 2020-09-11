/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"
#include "DNA_node_types.h"

/**
 * \brief TextureNode
 * \ingroup Node
 */
class TextureNode : public Node {
 public:
  TextureNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
