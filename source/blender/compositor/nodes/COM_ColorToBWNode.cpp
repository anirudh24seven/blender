/** Copyright 2011, Blender Foundation.
 */

#include "COM_ColorToBWNode.h"

#include "COM_ConvertOperation.h"
#include "COM_ExecutionSystem.h"

ColorToBWNode::ColorToBWNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void ColorToBWNode::convertToOperations(NodeConverter &converter,
                                        const CompositorContext & /*context*/) const
{
  NodeInput *colorSocket = this->getInputSocket(0);
  NodeOutput *valueSocket = this->getOutputSocket(0);

  ConvertColorToBWOperation *convertProg = new ConvertColorToBWOperation();
  converter.addOperation(convertProg);

  converter.mapInputSocket(colorSocket, convertProg->getInputSocket(0));
  converter.mapOutputSocket(valueSocket, convertProg->getOutputSocket(0));
}
