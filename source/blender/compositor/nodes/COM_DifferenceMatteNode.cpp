/** Copyright 2011, Blender Foundation.
 */

#include "COM_DifferenceMatteNode.h"
#include "BKE_node.h"
#include "COM_DifferenceMatteOperation.h"
#include "COM_SetAlphaOperation.h"

DifferenceMatteNode::DifferenceMatteNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void DifferenceMatteNode::convertToOperations(NodeConverter &converter,
                                              const CompositorContext & /*context*/) const
{
  NodeInput *inputSocket = this->getInputSocket(0);
  NodeInput *inputSocket2 = this->getInputSocket(1);
  NodeOutput *outputSocketImage = this->getOutputSocket(0);
  NodeOutput *outputSocketMatte = this->getOutputSocket(1);
  bNode *editorNode = this->getbNode();

  DifferenceMatteOperation *operationSet = new DifferenceMatteOperation();
  operationSet->setSettings((NodeChroma *)editorNode->storage);
  converter.addOperation(operationSet);

  converter.mapInputSocket(inputSocket, operationSet->getInputSocket(0));
  converter.mapInputSocket(inputSocket2, operationSet->getInputSocket(1));
  converter.mapOutputSocket(outputSocketMatte, operationSet->getOutputSocket(0));

  SetAlphaOperation *operation = new SetAlphaOperation();
  converter.addOperation(operation);

  converter.mapInputSocket(inputSocket, operation->getInputSocket(0));
  converter.addLink(operationSet->getOutputSocket(), operation->getInputSocket(1));
  converter.mapOutputSocket(outputSocketImage, operation->getOutputSocket());

  converter.addPreview(operation->getOutputSocket());
}
