/** Copyright 2012, Blender Foundation.
 */

#include "COM_NormalizeNode.h"
#include "COM_ExecutionSystem.h"
#include "COM_NormalizeOperation.h"

NormalizeNode::NormalizeNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void NormalizeNode::convertToOperations(NodeConverter &converter,
                                        const CompositorContext & /*context*/) const
{
  NormalizeOperation *operation = new NormalizeOperation();
  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket(0));
}
