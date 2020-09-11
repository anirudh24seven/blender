/** Copyright 2011, Blender Foundation.
 */

#include "COM_HueSaturationValueCorrectNode.h"

#include "COM_ConvertOperation.h"
#include "COM_ExecutionSystem.h"
#include "COM_HueSaturationValueCorrectOperation.h"
#include "COM_MixOperation.h"
#include "COM_SetColorOperation.h"
#include "COM_SetValueOperation.h"
#include "DNA_node_types.h"

HueSaturationValueCorrectNode::HueSaturationValueCorrectNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void HueSaturationValueCorrectNode::convertToOperations(
    NodeConverter &converter, const CompositorContext & /*context*/) const
{
  NodeInput *valueSocket = this->getInputSocket(0);
  NodeInput *colorSocket = this->getInputSocket(1);
  NodeOutput *outputSocket = this->getOutputSocket(0);
  bNode *editorsnode = getbNode();
  CurveMapping *storage = (CurveMapping *)editorsnode->storage;

  ConvertRGBToHSVOperation *rgbToHSV = new ConvertRGBToHSVOperation();
  converter.addOperation(rgbToHSV);

  ConvertHSVToRGBOperation *hsvToRGB = new ConvertHSVToRGBOperation();
  converter.addOperation(hsvToRGB);

  HueSaturationValueCorrectOperation *changeHSV = new HueSaturationValueCorrectOperation();
  changeHSV->setCurveMapping(storage);
  converter.addOperation(changeHSV);

  MixBlendOperation *blend = new MixBlendOperation();
  blend->setResolutionInputSocketIndex(1);
  converter.addOperation(blend);

  converter.mapInputSocket(colorSocket, rgbToHSV->getInputSocket(0));
  converter.addLink(rgbToHSV->getOutputSocket(), changeHSV->getInputSocket(0));
  converter.addLink(changeHSV->getOutputSocket(), hsvToRGB->getInputSocket(0));
  converter.addLink(hsvToRGB->getOutputSocket(), blend->getInputSocket(2));
  converter.mapInputSocket(colorSocket, blend->getInputSocket(1));
  converter.mapInputSocket(valueSocket, blend->getInputSocket(0));
  converter.mapOutputSocket(outputSocket, blend->getOutputSocket());
}
