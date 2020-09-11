/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"
#include "COM_RenderLayersProg.h"
#include "DNA_node_types.h"

struct Render;

/**
 * \brief RenderLayersNode
 * \ingroup Node
 */
class RenderLayersNode : public Node {
 public:
  RenderLayersNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;

 private:
  void testSocketLink(NodeConverter &converter,
                      const CompositorContext &context,
                      NodeOutput *output,
                      RenderLayersProg *operation,
                      Scene *scene,
                      int layerId,
                      bool is_preview) const;
  void testRenderLink(NodeConverter &converter,
                      const CompositorContext &context,
                      Render *re) const;

  void missingSocketLink(NodeConverter &converter, NodeOutput *output) const;
  void missingRenderLink(NodeConverter &converter) const;
};
