/** Copyright 2011, Blender Foundation.
 */

#include "COM_DirectionalBlurNode.h"
#include "COM_DirectionalBlurOperation.h"
#include "COM_ExecutionSystem.h"
#include "DNA_node_types.h"

DirectionalBlurNode::DirectionalBlurNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void DirectionalBlurNode::convertToOperations(NodeConverter &converter,
                                              const CompositorContext &context) const
{
  NodeDBlurData *data = (NodeDBlurData *)this->getbNode()->storage;
  DirectionalBlurOperation *operation = new DirectionalBlurOperation();
  operation->setQuality(context.getQuality());
  operation->setData(data);
  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket());
}
