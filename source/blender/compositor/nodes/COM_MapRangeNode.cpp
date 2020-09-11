/** Copyright 2012, Blender Foundation.
 */

#include "COM_MapRangeNode.h"

#include "COM_ExecutionSystem.h"
#include "COM_MapRangeOperation.h"

MapRangeNode::MapRangeNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void MapRangeNode::convertToOperations(NodeConverter &converter,
                                       const CompositorContext & /*context*/) const
{
  NodeInput *valueSocket = this->getInputSocket(0);
  NodeInput *sourceMinSocket = this->getInputSocket(1);
  NodeInput *sourceMaxSocket = this->getInputSocket(2);
  NodeInput *destMinSocket = this->getInputSocket(3);
  NodeInput *destMaxSocket = this->getInputSocket(4);
  NodeOutput *outputSocket = this->getOutputSocket(0);

  MapRangeOperation *operation = new MapRangeOperation();
  operation->setUseClamp(this->getbNode()->custom1);
  converter.addOperation(operation);

  converter.mapInputSocket(valueSocket, operation->getInputSocket(0));
  converter.mapInputSocket(sourceMinSocket, operation->getInputSocket(1));
  converter.mapInputSocket(sourceMaxSocket, operation->getInputSocket(2));
  converter.mapInputSocket(destMinSocket, operation->getInputSocket(3));
  converter.mapInputSocket(destMaxSocket, operation->getInputSocket(4));
  converter.mapOutputSocket(outputSocket, operation->getOutputSocket(0));
}
