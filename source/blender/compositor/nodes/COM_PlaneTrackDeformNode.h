/** Copyright 2013, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

#include "DNA_movieclip_types.h"
#include "DNA_node_types.h"

/**
 * \brief PlaneTrackDeformNode
 * \ingroup Node
 */
class PlaneTrackDeformNode : public Node {
 public:
  PlaneTrackDeformNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
