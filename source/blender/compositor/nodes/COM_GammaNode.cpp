/** Copyright 2011, Blender Foundation.
 */

#include "COM_GammaNode.h"
#include "COM_ExecutionSystem.h"
#include "COM_GammaOperation.h"

GammaNode::GammaNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void GammaNode::convertToOperations(NodeConverter &converter,
                                    const CompositorContext & /*context*/) const
{
  GammaOperation *operation = new GammaOperation();
  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket(0));
}
