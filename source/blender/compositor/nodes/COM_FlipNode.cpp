/** Copyright 2011, Blender Foundation.
 */

#include "COM_FlipNode.h"

#include "COM_ExecutionSystem.h"
#include "COM_FlipOperation.h"

FlipNode::FlipNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void FlipNode::convertToOperations(NodeConverter &converter,
                                   const CompositorContext & /*context*/) const
{
  NodeInput *inputSocket = this->getInputSocket(0);
  NodeOutput *outputSocket = this->getOutputSocket(0);
  FlipOperation *operation = new FlipOperation();
  switch (this->getbNode()->custom1) {
    case 0: /* TODO: I didn't find any constants in the old implementation,
             * should I introduce them. */
      operation->setFlipX(true);
      operation->setFlipY(false);
      break;
    case 1:
      operation->setFlipX(false);
      operation->setFlipY(true);
      break;
    case 2:
      operation->setFlipX(true);
      operation->setFlipY(true);
      break;
  }

  converter.addOperation(operation);
  converter.mapInputSocket(inputSocket, operation->getInputSocket(0));
  converter.mapOutputSocket(outputSocket, operation->getOutputSocket(0));
}
