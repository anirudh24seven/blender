/** Copyright 2011, Blender Foundation.
 */

#include "COM_ScaleNode.h"

#include "BKE_node.h"
#include "COM_ExecutionSystem.h"
#include "COM_ScaleOperation.h"
#include "COM_SetSamplerOperation.h"
#include "COM_SetValueOperation.h"

ScaleNode::ScaleNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void ScaleNode::convertToOperations(NodeConverter &converter,
                                    const CompositorContext &context) const
{
  bNode *bnode = this->getbNode();

  NodeInput *inputSocket = this->getInputSocket(0);
  NodeInput *inputXSocket = this->getInputSocket(1);
  NodeInput *inputYSocket = this->getInputSocket(2);
  NodeOutput *outputSocket = this->getOutputSocket(0);

  switch (bnode->custom1) {
    case CMP_SCALE_RELATIVE: {
      ScaleOperation *operation = new ScaleOperation();
      converter.addOperation(operation);

      converter.mapInputSocket(inputSocket, operation->getInputSocket(0));
      converter.mapInputSocket(inputXSocket, operation->getInputSocket(1));
      converter.mapInputSocket(inputYSocket, operation->getInputSocket(2));
      converter.mapOutputSocket(outputSocket, operation->getOutputSocket(0));

      operation->setVariableSize(inputXSocket->isLinked() || inputYSocket->isLinked());
      break;
    }
    case CMP_SCALE_SCENEPERCENT: {
      SetValueOperation *scaleFactorOperation = new SetValueOperation();
      scaleFactorOperation->setValue(context.getRenderData()->size / 100.0f);
      converter.addOperation(scaleFactorOperation);

      ScaleOperation *operation = new ScaleOperation();
      converter.addOperation(operation);

      converter.mapInputSocket(inputSocket, operation->getInputSocket(0));
      converter.addLink(scaleFactorOperation->getOutputSocket(), operation->getInputSocket(1));
      converter.addLink(scaleFactorOperation->getOutputSocket(), operation->getInputSocket(2));
      converter.mapOutputSocket(outputSocket, operation->getOutputSocket(0));

      operation->setVariableSize(inputXSocket->isLinked() || inputYSocket->isLinked());

      break;
    }
    case CMP_SCALE_RENDERPERCENT: {
      const RenderData *rd = context.getRenderData();
      ScaleFixedSizeOperation *operation = new ScaleFixedSizeOperation();
      /* framing options */
      operation->setIsAspect((bnode->custom2 & CMP_SCALE_RENDERSIZE_FRAME_ASPECT) != 0);
      operation->setIsCrop((bnode->custom2 & CMP_SCALE_RENDERSIZE_FRAME_CROP) != 0);
      operation->setOffset(bnode->custom3, bnode->custom4);
      operation->setNewWidth(rd->xsch * rd->size / 100.0f);
      operation->setNewHeight(rd->ysch * rd->size / 100.0f);
      operation->getInputSocket(0)->setResizeMode(COM_SC_NO_RESIZE);
      converter.addOperation(operation);

      converter.mapInputSocket(inputSocket, operation->getInputSocket(0));
      converter.mapOutputSocket(outputSocket, operation->getOutputSocket(0));

      operation->setVariableSize(inputXSocket->isLinked() || inputYSocket->isLinked());

      break;
    }
    case CMP_SCALE_ABSOLUTE: {
      /* TODO: what is the use of this one.... perhaps some issues when the ui was updated... */
      ScaleAbsoluteOperation *operation = new ScaleAbsoluteOperation();
      converter.addOperation(operation);

      converter.mapInputSocket(inputSocket, operation->getInputSocket(0));
      converter.mapInputSocket(inputXSocket, operation->getInputSocket(1));
      converter.mapInputSocket(inputYSocket, operation->getInputSocket(2));
      converter.mapOutputSocket(outputSocket, operation->getOutputSocket(0));

      operation->setVariableSize(inputXSocket->isLinked() || inputYSocket->isLinked());

      break;
    }
  }
}
