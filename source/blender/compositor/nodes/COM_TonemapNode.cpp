/** Copyright 2011, Blender Foundation.
 */

#include "COM_TonemapNode.h"
#include "COM_ExecutionSystem.h"
#include "COM_TonemapOperation.h"

TonemapNode::TonemapNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void TonemapNode::convertToOperations(NodeConverter &converter,
                                      const CompositorContext & /*context*/) const
{
  NodeTonemap *data = (NodeTonemap *)this->getbNode()->storage;

  TonemapOperation *operation = data->type == 1 ? new PhotoreceptorTonemapOperation() :
                                                  new TonemapOperation();
  operation->setData(data);
  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket(0));
}
