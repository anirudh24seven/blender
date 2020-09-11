/** Copyright 2011, Blender Foundation.
 */

#include "COM_BilateralBlurNode.h"
#include "COM_BilateralBlurOperation.h"
#include "COM_ExecutionSystem.h"
#include "DNA_node_types.h"

BilateralBlurNode::BilateralBlurNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void BilateralBlurNode::convertToOperations(NodeConverter &converter,
                                            const CompositorContext &context) const
{
  NodeBilateralBlurData *data = (NodeBilateralBlurData *)this->getbNode()->storage;
  BilateralBlurOperation *operation = new BilateralBlurOperation();
  operation->setQuality(context.getQuality());
  operation->setData(data);

  converter.addOperation(operation);
  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket(0));
}
