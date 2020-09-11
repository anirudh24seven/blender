/** Copyright 2011, Blender Foundation.
 */

#include "COM_BokehImageNode.h"
#include "COM_BokehImageOperation.h"
#include "COM_ExecutionSystem.h"

BokehImageNode::BokehImageNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void BokehImageNode::convertToOperations(NodeConverter &converter,
                                         const CompositorContext & /*context*/) const
{
  BokehImageOperation *operation = new BokehImageOperation();
  operation->setData((NodeBokehImage *)this->getbNode()->storage);

  converter.addOperation(operation);
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket(0));

  converter.addPreview(operation->getOutputSocket(0));
}
