/** Copyright 2011, Blender Foundation.
 */

#include "COM_SeparateColorNode.h"

#include "COM_ConvertOperation.h"

SeparateColorNode::SeparateColorNode(bNode *editorNode) : Node(editorNode)
{
}

void SeparateColorNode::convertToOperations(NodeConverter &converter,
                                            const CompositorContext &context) const
{
  NodeInput *imageSocket = this->getInputSocket(0);
  NodeOutput *outputRSocket = this->getOutputSocket(0);
  NodeOutput *outputGSocket = this->getOutputSocket(1);
  NodeOutput *outputBSocket = this->getOutputSocket(2);
  NodeOutput *outputASocket = this->getOutputSocket(3);

  NodeOperation *color_conv = getColorConverter(context);
  if (color_conv) {
    converter.addOperation(color_conv);

    converter.mapInputSocket(imageSocket, color_conv->getInputSocket(0));
  }

  {
    SeparateChannelOperation *operation = new SeparateChannelOperation();
    operation->setChannel(0);
    converter.addOperation(operation);

    if (color_conv) {
      converter.addLink(color_conv->getOutputSocket(), operation->getInputSocket(0));
    }
    else {
      converter.mapInputSocket(imageSocket, operation->getInputSocket(0));
    }
    converter.mapOutputSocket(outputRSocket, operation->getOutputSocket(0));
  }

  {
    SeparateChannelOperation *operation = new SeparateChannelOperation();
    operation->setChannel(1);
    converter.addOperation(operation);

    if (color_conv) {
      converter.addLink(color_conv->getOutputSocket(), operation->getInputSocket(0));
    }
    else {
      converter.mapInputSocket(imageSocket, operation->getInputSocket(0));
    }
    converter.mapOutputSocket(outputGSocket, operation->getOutputSocket(0));
  }

  {
    SeparateChannelOperation *operation = new SeparateChannelOperation();
    operation->setChannel(2);
    converter.addOperation(operation);

    if (color_conv) {
      converter.addLink(color_conv->getOutputSocket(), operation->getInputSocket(0));
    }
    else {
      converter.mapInputSocket(imageSocket, operation->getInputSocket(0));
    }
    converter.mapOutputSocket(outputBSocket, operation->getOutputSocket(0));
  }

  {
    SeparateChannelOperation *operation = new SeparateChannelOperation();
    operation->setChannel(3);
    converter.addOperation(operation);

    if (color_conv) {
      converter.addLink(color_conv->getOutputSocket(), operation->getInputSocket(0));
    }
    else {
      converter.mapInputSocket(imageSocket, operation->getInputSocket(0));
    }
    converter.mapOutputSocket(outputASocket, operation->getOutputSocket(0));
  }
}

NodeOperation *SeparateRGBANode::getColorConverter(const CompositorContext & /*context*/) const
{
  return NULL; /* no conversion needed */
}

NodeOperation *SeparateHSVANode::getColorConverter(const CompositorContext & /*context*/) const
{
  return new ConvertRGBToHSVOperation();
}

NodeOperation *SeparateYCCANode::getColorConverter(const CompositorContext & /*context*/) const
{
  ConvertRGBToYCCOperation *operation = new ConvertRGBToYCCOperation();
  bNode *editorNode = this->getbNode();
  operation->setMode(editorNode->custom1);
  return operation;
}

NodeOperation *SeparateYUVANode::getColorConverter(const CompositorContext & /*context*/) const
{
  return new ConvertRGBToYUVOperation();
}
