/** Copyright 2011, Blender Foundation.
 */

#include "COM_DoubleEdgeMaskNode.h"
#include "COM_DoubleEdgeMaskOperation.h"
#include "COM_ExecutionSystem.h"

DoubleEdgeMaskNode::DoubleEdgeMaskNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void DoubleEdgeMaskNode::convertToOperations(NodeConverter &converter,
                                             const CompositorContext & /*context*/) const
{
  DoubleEdgeMaskOperation *operation;
  bNode *bnode = this->getbNode();

  operation = new DoubleEdgeMaskOperation();
  operation->setAdjecentOnly(bnode->custom1);
  operation->setKeepInside(bnode->custom2);
  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket(0));
}
