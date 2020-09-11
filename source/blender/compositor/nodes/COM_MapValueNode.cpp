/** Copyright 2011, Blender Foundation.
 */

#include "COM_MapValueNode.h"

#include "COM_ExecutionSystem.h"
#include "COM_MapValueOperation.h"

MapValueNode::MapValueNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void MapValueNode::convertToOperations(NodeConverter &converter,
                                       const CompositorContext & /*context*/) const
{
  TexMapping *storage = (TexMapping *)this->getbNode()->storage;

  NodeInput *colorSocket = this->getInputSocket(0);
  NodeOutput *valueSocket = this->getOutputSocket(0);

  MapValueOperation *convertProg = new MapValueOperation();
  convertProg->setSettings(storage);
  converter.addOperation(convertProg);

  converter.mapInputSocket(colorSocket, convertProg->getInputSocket(0));
  converter.mapOutputSocket(valueSocket, convertProg->getOutputSocket(0));
}
