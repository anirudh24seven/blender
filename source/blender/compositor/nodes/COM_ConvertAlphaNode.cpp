/** Copyright 2012, Blender Foundation.
 */

#include "COM_ConvertAlphaNode.h"
#include "COM_ConvertOperation.h"
#include "COM_ExecutionSystem.h"

void ConvertAlphaNode::convertToOperations(NodeConverter &converter,
                                           const CompositorContext & /*context*/) const
{
  NodeOperation *operation = NULL;
  bNode *node = this->getbNode();

  /* value hardcoded in rna_nodetree.c */
  if (node->custom1 == 1) {
    operation = new ConvertPremulToStraightOperation();
  }
  else {
    operation = new ConvertStraightToPremulOperation();
  }

  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket());
}
