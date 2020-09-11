/** Copyright 2011, Blender Foundation.
 */

#include "COM_VectorBlurNode.h"
#include "COM_VectorBlurOperation.h"
#include "DNA_node_types.h"

VectorBlurNode::VectorBlurNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void VectorBlurNode::convertToOperations(NodeConverter &converter,
                                         const CompositorContext &context) const
{
  bNode *node = this->getbNode();
  NodeBlurData *vectorBlurSettings = (NodeBlurData *)node->storage;

  VectorBlurOperation *operation = new VectorBlurOperation();
  operation->setVectorBlurSettings(vectorBlurSettings);
  operation->setQuality(context.getQuality());
  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
  converter.mapInputSocket(getInputSocket(2), operation->getInputSocket(2));
  converter.mapOutputSocket(getOutputSocket(), operation->getOutputSocket());
}
