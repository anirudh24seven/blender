/** Copyright 2011, Blender Foundation.
 */

#include "COM_LuminanceMatteNode.h"
#include "BKE_node.h"
#include "COM_ConvertOperation.h"
#include "COM_LuminanceMatteOperation.h"
#include "COM_SetAlphaOperation.h"

LuminanceMatteNode::LuminanceMatteNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void LuminanceMatteNode::convertToOperations(NodeConverter &converter,
                                             const CompositorContext & /*context*/) const
{
  bNode *editorsnode = getbNode();
  NodeInput *inputSocket = this->getInputSocket(0);
  NodeOutput *outputSocketImage = this->getOutputSocket(0);
  NodeOutput *outputSocketMatte = this->getOutputSocket(1);

  LuminanceMatteOperation *operationSet = new LuminanceMatteOperation();
  operationSet->setSettings((NodeChroma *)editorsnode->storage);
  converter.addOperation(operationSet);

  converter.mapInputSocket(inputSocket, operationSet->getInputSocket(0));
  converter.mapOutputSocket(outputSocketMatte, operationSet->getOutputSocket(0));

  SetAlphaOperation *operation = new SetAlphaOperation();
  converter.addOperation(operation);

  converter.mapInputSocket(inputSocket, operation->getInputSocket(0));
  converter.addLink(operationSet->getOutputSocket(), operation->getInputSocket(1));
  converter.mapOutputSocket(outputSocketImage, operation->getOutputSocket());

  converter.addPreview(operation->getOutputSocket());
}
