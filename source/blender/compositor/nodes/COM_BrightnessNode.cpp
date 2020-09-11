/** Copyright 2011, Blender Foundation.
 */

#include "COM_BrightnessNode.h"
#include "COM_BrightnessOperation.h"
#include "COM_ExecutionSystem.h"

BrightnessNode::BrightnessNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void BrightnessNode::convertToOperations(NodeConverter &converter,
                                         const CompositorContext & /*context*/) const
{
  bNode *bnode = this->getbNode();
  BrightnessOperation *operation = new BrightnessOperation();
  operation->setUsePremultiply((bnode->custom1 & 1) != 0);
  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
  converter.mapInputSocket(getInputSocket(2), operation->getInputSocket(2));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket(0));
}
