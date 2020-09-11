/** Copyright 2011, Blender Foundation.
 */

#include "COM_LensDistortionNode.h"
#include "COM_ExecutionSystem.h"
#include "COM_ProjectorLensDistortionOperation.h"
#include "COM_ScreenLensDistortionOperation.h"

LensDistortionNode::LensDistortionNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void LensDistortionNode::convertToOperations(NodeConverter &converter,
                                             const CompositorContext & /*context*/) const
{
  bNode *editorNode = this->getbNode();
  NodeLensDist *data = (NodeLensDist *)editorNode->storage;
  if (data->proj) {
    ProjectorLensDistortionOperation *operation = new ProjectorLensDistortionOperation();
    converter.addOperation(operation);

    converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
    converter.mapInputSocket(getInputSocket(2), operation->getInputSocket(1));
    converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket(0));
  }
  else {
    ScreenLensDistortionOperation *operation = new ScreenLensDistortionOperation();
    operation->setFit(data->fit);
    operation->setJitter(data->jit);

    if (!getInputSocket(1)->isLinked()) {
      operation->setDistortion(getInputSocket(1)->getEditorValueFloat());
    }
    if (!getInputSocket(2)->isLinked()) {
      operation->setDispersion(getInputSocket(2)->getEditorValueFloat());
    }

    converter.addOperation(operation);

    converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
    converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
    converter.mapInputSocket(getInputSocket(2), operation->getInputSocket(2));
    converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket(0));
  }
}
