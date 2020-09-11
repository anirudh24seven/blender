/** Copyright 2011, Blender Foundation.
 */

#include "COM_NormalNode.h"
#include "BKE_node.h"
#include "COM_DotproductOperation.h"
#include "COM_ExecutionSystem.h"
#include "COM_SetVectorOperation.h"

NormalNode::NormalNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void NormalNode::convertToOperations(NodeConverter &converter,
                                     const CompositorContext & /*context*/) const
{
  NodeInput *inputSocket = this->getInputSocket(0);
  NodeOutput *outputSocket = this->getOutputSocket(0);
  NodeOutput *outputSocketDotproduct = this->getOutputSocket(1);

  SetVectorOperation *operationSet = new SetVectorOperation();
  float normal[3];
  outputSocket->getEditorValueVector(normal);
  /* animation can break normalization, this restores it */
  normalize_v3(normal);
  operationSet->setX(normal[0]);
  operationSet->setY(normal[1]);
  operationSet->setZ(normal[2]);
  operationSet->setW(0.0f);
  converter.addOperation(operationSet);

  converter.mapOutputSocket(outputSocket, operationSet->getOutputSocket(0));

  DotproductOperation *operation = new DotproductOperation();
  converter.addOperation(operation);

  converter.mapInputSocket(inputSocket, operation->getInputSocket(0));
  converter.addLink(operationSet->getOutputSocket(0), operation->getInputSocket(1));
  converter.mapOutputSocket(outputSocketDotproduct, operation->getOutputSocket(0));
}
