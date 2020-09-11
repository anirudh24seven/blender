/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief ChromaMatteNode
 * \ingroup Node
 */
class ChromaMatteNode : public Node {
 public:
  ChromaMatteNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
