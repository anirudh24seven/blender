/** Copyright 2011, Blender Foundation.
 */

#include "COM_DisplaceNode.h"
#include "COM_DisplaceOperation.h"
#include "COM_DisplaceSimpleOperation.h"
#include "COM_ExecutionSystem.h"

DisplaceNode::DisplaceNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void DisplaceNode::convertToOperations(NodeConverter &converter,
                                       const CompositorContext &context) const
{
  NodeOperation *operation;
  if (context.getQuality() == COM_QUALITY_LOW) {
    operation = new DisplaceSimpleOperation();
  }
  else {
    operation = new DisplaceOperation();
  }
  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
  converter.mapInputSocket(getInputSocket(2), operation->getInputSocket(2));
  converter.mapInputSocket(getInputSocket(3), operation->getInputSocket(3));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket());
}
