/** Copyright 2011, Blender Foundation.
 */

#include "COM_ColorSpillNode.h"
#include "BKE_node.h"
#include "COM_ColorSpillOperation.h"

ColorSpillNode::ColorSpillNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void ColorSpillNode::convertToOperations(NodeConverter &converter,
                                         const CompositorContext & /*context*/) const
{
  bNode *editorsnode = getbNode();

  NodeInput *inputSocketImage = this->getInputSocket(0);
  NodeInput *inputSocketFac = this->getInputSocket(1);
  NodeOutput *outputSocketImage = this->getOutputSocket(0);

  ColorSpillOperation *operation;
  operation = new ColorSpillOperation();
  operation->setSettings((NodeColorspill *)editorsnode->storage);
  operation->setSpillChannel(editorsnode->custom1 - 1);  // Channel for spilling
  operation->setSpillMethod(editorsnode->custom2);       // Channel method
  converter.addOperation(operation);

  converter.mapInputSocket(inputSocketImage, operation->getInputSocket(0));
  converter.mapInputSocket(inputSocketFac, operation->getInputSocket(1));
  converter.mapOutputSocket(outputSocketImage, operation->getOutputSocket());
}
