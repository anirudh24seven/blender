/** Copyright 2011, Blender Foundation.
 */

#include "COM_ValueNode.h"
#include "COM_ExecutionSystem.h"
#include "COM_SetValueOperation.h"

ValueNode::ValueNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void ValueNode::convertToOperations(NodeConverter &converter,
                                    const CompositorContext & /*context*/) const
{
  SetValueOperation *operation = new SetValueOperation();
  NodeOutput *output = this->getOutputSocket(0);
  operation->setValue(output->getEditorValueFloat());
  converter.addOperation(operation);

  converter.mapOutputSocket(output, operation->getOutputSocket());
}
