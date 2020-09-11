/** Copyright 2011, Blender Foundation.
 */

#include "COM_VectorCurveNode.h"
#include "COM_ExecutionSystem.h"
#include "COM_VectorCurveOperation.h"

VectorCurveNode::VectorCurveNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void VectorCurveNode::convertToOperations(NodeConverter &converter,
                                          const CompositorContext & /*context*/) const
{
  VectorCurveOperation *operation = new VectorCurveOperation();
  operation->setCurveMapping((CurveMapping *)this->getbNode()->storage);
  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket());
}
