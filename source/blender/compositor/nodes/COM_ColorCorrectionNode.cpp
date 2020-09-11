/** Copyright 2011, Blender Foundation.
 */

#include "COM_ColorCorrectionNode.h"
#include "COM_ColorCorrectionOperation.h"
#include "COM_ExecutionSystem.h"

ColorCorrectionNode::ColorCorrectionNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void ColorCorrectionNode::convertToOperations(NodeConverter &converter,
                                              const CompositorContext & /*context*/) const
{
  bNode *editorNode = getbNode();

  ColorCorrectionOperation *operation = new ColorCorrectionOperation();
  operation->setData((NodeColorCorrection *)editorNode->storage);
  operation->setRedChannelEnabled((editorNode->custom1 & 1) > 0);
  operation->setGreenChannelEnabled((editorNode->custom1 & 2) > 0);
  operation->setBlueChannelEnabled((editorNode->custom1 & 4) > 0);
  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket(0));
}
