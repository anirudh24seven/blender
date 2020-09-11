/** Copyright 2011, Blender Foundation.
 */

#include "COM_SwitchNode.h"

SwitchNode::SwitchNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void SwitchNode::convertToOperations(NodeConverter &converter,
                                     const CompositorContext & /*context*/) const
{
  bool condition = this->getbNode()->custom1;

  NodeOperationOutput *result;
  if (!condition) {
    result = converter.addInputProxy(getInputSocket(0), false);
  }
  else {
    result = converter.addInputProxy(getInputSocket(1), false);
  }

  converter.mapOutputSocket(getOutputSocket(0), result);
}
