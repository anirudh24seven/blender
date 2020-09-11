/** Copyright 2011, Blender Foundation.
 */

#include "COM_SetAlphaNode.h"
#include "COM_ExecutionSystem.h"
#include "COM_SetAlphaOperation.h"

void SetAlphaNode::convertToOperations(NodeConverter &converter,
                                       const CompositorContext & /*context*/) const
{
  SetAlphaOperation *operation = new SetAlphaOperation();

  if (!this->getInputSocket(0)->isLinked() && this->getInputSocket(1)->isLinked()) {
    operation->setResolutionInputSocketIndex(1);
  }

  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket());
}
