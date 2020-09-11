/** Copyright 2011, Blender Foundation.
 */

#include "COM_RotateNode.h"

#include "COM_ExecutionSystem.h"
#include "COM_RotateOperation.h"
#include "COM_SetSamplerOperation.h"

RotateNode::RotateNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void RotateNode::convertToOperations(NodeConverter &converter,
                                     const CompositorContext & /*context*/) const
{
  NodeInput *inputSocket = this->getInputSocket(0);
  NodeInput *inputDegreeSocket = this->getInputSocket(1);
  NodeOutput *outputSocket = this->getOutputSocket(0);
  RotateOperation *operation = new RotateOperation();
  SetSamplerOperation *sampler = new SetSamplerOperation();
  sampler->setSampler((PixelSampler)this->getbNode()->custom1);

  converter.addOperation(sampler);
  converter.addOperation(operation);

  converter.addLink(sampler->getOutputSocket(), operation->getInputSocket(0));
  converter.mapInputSocket(inputSocket, sampler->getInputSocket(0));
  converter.mapInputSocket(inputDegreeSocket, operation->getInputSocket(1));
  converter.mapOutputSocket(outputSocket, operation->getOutputSocket(0));
}
