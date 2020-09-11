/** Copyright 2011, Blender Foundation.
 */

#include "COM_EllipseMaskNode.h"
#include "COM_EllipseMaskOperation.h"
#include "COM_ExecutionSystem.h"

#include "COM_ScaleOperation.h"
#include "COM_SetValueOperation.h"

EllipseMaskNode::EllipseMaskNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void EllipseMaskNode::convertToOperations(NodeConverter &converter,
                                          const CompositorContext &context) const
{
  NodeInput *inputSocket = this->getInputSocket(0);
  NodeOutput *outputSocket = this->getOutputSocket(0);

  EllipseMaskOperation *operation;
  operation = new EllipseMaskOperation();
  operation->setData((NodeEllipseMask *)this->getbNode()->storage);
  operation->setMaskType(this->getbNode()->custom1);
  converter.addOperation(operation);

  if (inputSocket->isLinked()) {
    converter.mapInputSocket(inputSocket, operation->getInputSocket(0));
    converter.mapOutputSocket(outputSocket, operation->getOutputSocket());
  }
  else {
    /* Value operation to produce original transparent image */
    SetValueOperation *valueOperation = new SetValueOperation();
    valueOperation->setValue(0.0f);
    converter.addOperation(valueOperation);

    /* Scale that image up to render resolution */
    const RenderData *rd = context.getRenderData();
    ScaleFixedSizeOperation *scaleOperation = new ScaleFixedSizeOperation();
    scaleOperation->setIsAspect(false);
    scaleOperation->setIsCrop(false);
    scaleOperation->setOffset(0.0f, 0.0f);
    scaleOperation->setNewWidth(rd->xsch * rd->size / 100.0f);
    scaleOperation->setNewHeight(rd->ysch * rd->size / 100.0f);
    scaleOperation->getInputSocket(0)->setResizeMode(COM_SC_NO_RESIZE);
    converter.addOperation(scaleOperation);

    converter.addLink(valueOperation->getOutputSocket(0), scaleOperation->getInputSocket(0));
    converter.addLink(scaleOperation->getOutputSocket(0), operation->getInputSocket(0));
    converter.mapOutputSocket(outputSocket, operation->getOutputSocket(0));
  }

  converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
}
