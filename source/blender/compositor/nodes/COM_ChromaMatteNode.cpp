/** Copyright 2011, Blender Foundation.
 */

#include "COM_ChromaMatteNode.h"
#include "BKE_node.h"
#include "COM_ChromaMatteOperation.h"
#include "COM_ConvertOperation.h"
#include "COM_SetAlphaOperation.h"

ChromaMatteNode::ChromaMatteNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void ChromaMatteNode::convertToOperations(NodeConverter &converter,
                                          const CompositorContext & /*context*/) const
{
  bNode *editorsnode = getbNode();

  NodeInput *inputSocketImage = this->getInputSocket(0);
  NodeInput *inputSocketKey = this->getInputSocket(1);
  NodeOutput *outputSocketImage = this->getOutputSocket(0);
  NodeOutput *outputSocketMatte = this->getOutputSocket(1);

  ConvertRGBToYCCOperation *operationRGBToYCC_Image = new ConvertRGBToYCCOperation();
  ConvertRGBToYCCOperation *operationRGBToYCC_Key = new ConvertRGBToYCCOperation();
  operationRGBToYCC_Image->setMode(BLI_YCC_ITU_BT709);
  operationRGBToYCC_Key->setMode(BLI_YCC_ITU_BT709);
  converter.addOperation(operationRGBToYCC_Image);
  converter.addOperation(operationRGBToYCC_Key);

  ChromaMatteOperation *operation = new ChromaMatteOperation();
  operation->setSettings((NodeChroma *)editorsnode->storage);
  converter.addOperation(operation);

  SetAlphaOperation *operationAlpha = new SetAlphaOperation();
  converter.addOperation(operationAlpha);

  converter.mapInputSocket(inputSocketImage, operationRGBToYCC_Image->getInputSocket(0));
  converter.mapInputSocket(inputSocketKey, operationRGBToYCC_Key->getInputSocket(0));
  converter.addLink(operationRGBToYCC_Image->getOutputSocket(), operation->getInputSocket(0));
  converter.addLink(operationRGBToYCC_Key->getOutputSocket(), operation->getInputSocket(1));
  converter.mapOutputSocket(outputSocketMatte, operation->getOutputSocket());

  converter.mapInputSocket(inputSocketImage, operationAlpha->getInputSocket(0));
  converter.addLink(operation->getOutputSocket(), operationAlpha->getInputSocket(1));
  converter.mapOutputSocket(outputSocketImage, operationAlpha->getOutputSocket());

  converter.addPreview(operationAlpha->getOutputSocket());
}
