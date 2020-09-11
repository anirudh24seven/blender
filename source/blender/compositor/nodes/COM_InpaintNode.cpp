/** Copyright 2011, Blender Foundation.
 */

#include "COM_InpaintNode.h"
#include "BLI_math.h"
#include "COM_ExecutionSystem.h"
#include "COM_InpaintOperation.h"
#include "DNA_scene_types.h"

InpaintNode::InpaintNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void InpaintNode::convertToOperations(NodeConverter &converter,
                                      const CompositorContext & /*context*/) const
{

  bNode *editorNode = this->getbNode();

  /* if (editorNode->custom1 == CMP_NODE_INPAINT_SIMPLE) { */
  if (true) {
    InpaintSimpleOperation *operation = new InpaintSimpleOperation();
    operation->setIterations(editorNode->custom2);
    converter.addOperation(operation);

    converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
    converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket(0));
  }
}
