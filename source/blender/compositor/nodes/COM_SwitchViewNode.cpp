/** Copyright 2015, Blender Foundation.
 */

#include "COM_SwitchViewNode.h"
#include "BLI_listbase.h"

SwitchViewNode::SwitchViewNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void SwitchViewNode::convertToOperations(NodeConverter &converter,
                                         const CompositorContext &context) const
{
  NodeOperationOutput *result;
  const char *viewName = context.getViewName();
  bNode *bnode = this->getbNode();

  /* get the internal index of the socket with a matching name */
  int nr = BLI_findstringindex(&bnode->inputs, viewName, offsetof(bNodeSocket, name));
  nr = max(nr, 0);

  result = converter.addInputProxy(getInputSocket(nr), false);
  converter.mapOutputSocket(getOutputSocket(0), result);
}
