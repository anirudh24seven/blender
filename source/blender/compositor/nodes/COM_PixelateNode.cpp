/** Copyright 2011, Blender Foundation.
 */

#include "COM_PixelateNode.h"

#include "COM_ExecutionSystem.h"
#include "COM_PixelateOperation.h"

PixelateNode::PixelateNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void PixelateNode::convertToOperations(NodeConverter &converter,
                                       const CompositorContext & /*context*/) const
{
  NodeInput *inputSocket = this->getInputSocket(0);
  NodeOutput *outputSocket = this->getOutputSocket(0);
  DataType datatype = inputSocket->getDataType();

  if (inputSocket->isLinked()) {
    NodeOutput *link = inputSocket->getLink();
    datatype = link->getDataType();
  }

  PixelateOperation *operation = new PixelateOperation(datatype);
  converter.addOperation(operation);

  converter.mapInputSocket(inputSocket, operation->getInputSocket(0));
  converter.mapOutputSocket(outputSocket, operation->getOutputSocket(0));
}
