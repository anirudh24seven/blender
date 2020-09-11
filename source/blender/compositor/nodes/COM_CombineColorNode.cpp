/** Copyright 2011, Blender Foundation.
 */

#include "COM_CombineColorNode.h"

#include "COM_ConvertOperation.h"

CombineColorNode::CombineColorNode(bNode *editorNode) : Node(editorNode)
{
}

void CombineColorNode::convertToOperations(NodeConverter &converter,
                                           const CompositorContext &context) const
{
  NodeInput *inputRSocket = this->getInputSocket(0);
  NodeInput *inputGSocket = this->getInputSocket(1);
  NodeInput *inputBSocket = this->getInputSocket(2);
  NodeInput *inputASocket = this->getInputSocket(3);
  NodeOutput *outputSocket = this->getOutputSocket(0);

  CombineChannelsOperation *operation = new CombineChannelsOperation();
  if (inputRSocket->isLinked()) {
    operation->setResolutionInputSocketIndex(0);
  }
  else if (inputGSocket->isLinked()) {
    operation->setResolutionInputSocketIndex(1);
  }
  else if (inputBSocket->isLinked()) {
    operation->setResolutionInputSocketIndex(2);
  }
  else {
    operation->setResolutionInputSocketIndex(3);
  }
  converter.addOperation(operation);

  converter.mapInputSocket(inputRSocket, operation->getInputSocket(0));
  converter.mapInputSocket(inputGSocket, operation->getInputSocket(1));
  converter.mapInputSocket(inputBSocket, operation->getInputSocket(2));
  converter.mapInputSocket(inputASocket, operation->getInputSocket(3));

  NodeOperation *color_conv = getColorConverter(context);
  if (color_conv) {
    converter.addOperation(color_conv);

    converter.addLink(operation->getOutputSocket(), color_conv->getInputSocket(0));
    converter.mapOutputSocket(outputSocket, color_conv->getOutputSocket());
  }
  else {
    converter.mapOutputSocket(outputSocket, operation->getOutputSocket());
  }
}

NodeOperation *CombineRGBANode::getColorConverter(const CompositorContext & /*context*/) const
{
  return NULL; /* no conversion needed */
}

NodeOperation *CombineHSVANode::getColorConverter(const CompositorContext & /*context*/) const
{
  return new ConvertHSVToRGBOperation();
}

NodeOperation *CombineYCCANode::getColorConverter(const CompositorContext & /*context*/) const
{
  ConvertYCCToRGBOperation *operation = new ConvertYCCToRGBOperation();
  bNode *editorNode = this->getbNode();
  operation->setMode(editorNode->custom1);
  return operation;
}

NodeOperation *CombineYUVANode::getColorConverter(const CompositorContext & /*context*/) const
{
  return new ConvertYUVToRGBOperation();
}
