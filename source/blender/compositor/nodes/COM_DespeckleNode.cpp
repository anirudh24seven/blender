/** Copyright 2011, Blender Foundation.
 */

#include "COM_DespeckleNode.h"
#include "BLI_math.h"
#include "COM_DespeckleOperation.h"
#include "COM_ExecutionSystem.h"
#include "DNA_scene_types.h"

DespeckleNode::DespeckleNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void DespeckleNode::convertToOperations(NodeConverter &converter,
                                        const CompositorContext & /*context*/) const
{
  bNode *editorNode = this->getbNode();
  NodeInput *inputSocket = this->getInputSocket(0);
  NodeInput *inputImageSocket = this->getInputSocket(1);
  NodeOutput *outputSocket = this->getOutputSocket(0);

  DespeckleOperation *operation = new DespeckleOperation();
  operation->setThreshold(editorNode->custom3);
  operation->setThresholdNeighbor(editorNode->custom4);
  converter.addOperation(operation);

  converter.mapInputSocket(inputImageSocket, operation->getInputSocket(0));
  converter.mapInputSocket(inputSocket, operation->getInputSocket(1));
  converter.mapOutputSocket(outputSocket, operation->getOutputSocket());

  converter.addPreview(operation->getOutputSocket(0));
}
