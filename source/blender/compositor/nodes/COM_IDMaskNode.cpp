/** Copyright 2011, Blender Foundation.
 */

#include "COM_IDMaskNode.h"
#include "COM_AntiAliasOperation.h"
#include "COM_ExecutionSystem.h"
#include "COM_IDMaskOperation.h"

IDMaskNode::IDMaskNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}
void IDMaskNode::convertToOperations(NodeConverter &converter,
                                     const CompositorContext &context) const
{
  bNode *bnode = this->getbNode();

  IDMaskOperation *operation;
  operation = new IDMaskOperation();
  operation->setObjectIndex(bnode->custom1);
  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  if (bnode->custom2 == 0 || context.getRenderData()->scemode & R_FULL_SAMPLE) {
    converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket(0));
  }
  else {
    AntiAliasOperation *antiAliasOperation = new AntiAliasOperation();
    converter.addOperation(antiAliasOperation);

    converter.addLink(operation->getOutputSocket(), antiAliasOperation->getInputSocket(0));
    converter.mapOutputSocket(getOutputSocket(0), antiAliasOperation->getOutputSocket(0));
  }
}
