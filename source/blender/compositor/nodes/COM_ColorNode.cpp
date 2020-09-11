/** Copyright 2011, Blender Foundation.
 */

#include "COM_ColorNode.h"
#include "COM_ExecutionSystem.h"
#include "COM_SetColorOperation.h"

ColorNode::ColorNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void ColorNode::convertToOperations(NodeConverter &converter,
                                    const CompositorContext & /*context*/) const
{
  SetColorOperation *operation = new SetColorOperation();
  NodeOutput *output = this->getOutputSocket(0);
  float col[4];
  output->getEditorValueColor(col);
  operation->setChannels(col);
  converter.addOperation(operation);

  converter.mapOutputSocket(output, operation->getOutputSocket());
}
