/** Copyright 2011, Blender Foundation.
 */

#include "COM_MapUVNode.h"
#include "COM_ExecutionSystem.h"
#include "COM_MapUVOperation.h"

MapUVNode::MapUVNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void MapUVNode::convertToOperations(NodeConverter &converter,
                                    const CompositorContext & /*context*/) const
{
  bNode *node = this->getbNode();

  MapUVOperation *operation = new MapUVOperation();
  operation->setAlpha((float)node->custom1);
  operation->setResolutionInputSocketIndex(1);
  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket());
}
