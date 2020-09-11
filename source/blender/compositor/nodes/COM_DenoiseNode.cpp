/** Copyright 2019, Blender Foundation.
 */
#include "COM_DenoiseNode.h"
#include "COM_DenoiseOperation.h"
#include "COM_MixOperation.h"
#include "COM_SetValueOperation.h"
#include "DNA_node_types.h"

DenoiseNode::DenoiseNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void DenoiseNode::convertToOperations(NodeConverter &converter,
                                      const CompositorContext & /*context*/) const
{
  bNode *node = this->getbNode();
  NodeDenoise *denoise = (NodeDenoise *)node->storage;

  DenoiseOperation *operation = new DenoiseOperation();
  converter.addOperation(operation);
  operation->setDenoiseSettings(denoise);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
  converter.mapInputSocket(getInputSocket(2), operation->getInputSocket(2));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket(0));
}
