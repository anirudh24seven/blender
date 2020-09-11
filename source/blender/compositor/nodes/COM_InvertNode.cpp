/** Copyright 2011, Blender Foundation.
 */

#include "COM_InvertNode.h"
#include "BKE_node.h"
#include "COM_ExecutionSystem.h"
#include "COM_InvertOperation.h"

InvertNode::InvertNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void InvertNode::convertToOperations(NodeConverter &converter,
                                     const CompositorContext & /*context*/) const
{
  InvertOperation *operation = new InvertOperation();
  bNode *node = this->getbNode();
  operation->setColor(node->custom1 & CMP_CHAN_RGB);
  operation->setAlpha(node->custom1 & CMP_CHAN_A);
  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket(0));
}
