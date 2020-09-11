/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief MovieDistortionNode
 * \ingroup Node
 */
class MovieDistortionNode : public Node {
 public:
  MovieDistortionNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
