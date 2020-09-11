/** Copyright 2011, Blender Foundation.
 */

#include "COM_CropNode.h"
#include "COM_CropOperation.h"

CropNode::CropNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void CropNode::convertToOperations(NodeConverter &converter,
                                   const CompositorContext & /*context*/) const
{
  bNode *node = getbNode();
  NodeTwoXYs *cropSettings = (NodeTwoXYs *)node->storage;
  bool relative = (bool)node->custom2;
  bool cropImage = (bool)node->custom1;
  CropBaseOperation *operation;
  if (cropImage) {
    operation = new CropImageOperation();
  }
  else {
    operation = new CropOperation();
  }
  operation->setCropSettings(cropSettings);
  operation->setRelative(relative);
  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapOutputSocket(getOutputSocket(), operation->getOutputSocket());
}
