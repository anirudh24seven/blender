/** Copyright 2011, Blender Foundation.
 */

#include "COM_TranslateNode.h"

#include "COM_ExecutionSystem.h"
#include "COM_TranslateOperation.h"
#include "COM_WrapOperation.h"
#include "COM_WriteBufferOperation.h"

TranslateNode::TranslateNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void TranslateNode::convertToOperations(NodeConverter &converter,
                                        const CompositorContext &context) const
{
  bNode *bnode = this->getbNode();
  NodeTranslateData *data = (NodeTranslateData *)bnode->storage;

  NodeInput *inputSocket = this->getInputSocket(0);
  NodeInput *inputXSocket = this->getInputSocket(1);
  NodeInput *inputYSocket = this->getInputSocket(2);
  NodeOutput *outputSocket = this->getOutputSocket(0);

  TranslateOperation *operation = new TranslateOperation();
  if (data->relative) {
    const RenderData *rd = context.getRenderData();
    float fx = rd->xsch * rd->size / 100.0f;
    float fy = rd->ysch * rd->size / 100.0f;

    operation->setFactorXY(fx, fy);
  }

  converter.addOperation(operation);
  converter.mapInputSocket(inputXSocket, operation->getInputSocket(1));
  converter.mapInputSocket(inputYSocket, operation->getInputSocket(2));
  converter.mapOutputSocket(outputSocket, operation->getOutputSocket(0));

  if (data->wrap_axis) {
    WriteBufferOperation *writeOperation = new WriteBufferOperation(COM_DT_COLOR);
    WrapOperation *wrapOperation = new WrapOperation(COM_DT_COLOR);
    wrapOperation->setMemoryProxy(writeOperation->getMemoryProxy());
    wrapOperation->setWrapping(data->wrap_axis);

    converter.addOperation(writeOperation);
    converter.addOperation(wrapOperation);
    converter.mapInputSocket(inputSocket, writeOperation->getInputSocket(0));
    converter.addLink(wrapOperation->getOutputSocket(), operation->getInputSocket(0));
  }
  else {
    converter.mapInputSocket(inputSocket, operation->getInputSocket(0));
  }
}
