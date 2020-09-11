#include "COM_SunBeamsNode.h"
#include "COM_SunBeamsOperation.h"

SunBeamsNode::SunBeamsNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void SunBeamsNode::convertToOperations(NodeConverter &converter,
                                       const CompositorContext & /*context*/) const
{
  NodeInput *inputSocket = this->getInputSocket(0);
  NodeOutput *outputSocket = this->getOutputSocket(0);
  NodeSunBeams *data = (NodeSunBeams *)getbNode()->storage;

  SunBeamsOperation *operation = new SunBeamsOperation();
  operation->setData(*data);
  converter.addOperation(operation);

  converter.mapInputSocket(inputSocket, operation->getInputSocket(0));
  converter.mapOutputSocket(outputSocket, operation->getOutputSocket(0));
}
