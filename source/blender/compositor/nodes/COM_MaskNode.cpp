/** Copyright 2012, Blender Foundation.
 */

#include "COM_MaskNode.h"
#include "COM_ExecutionSystem.h"
#include "COM_MaskOperation.h"

#include "DNA_mask_types.h"

MaskNode::MaskNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void MaskNode::convertToOperations(NodeConverter &converter,
                                   const CompositorContext &context) const
{
  const RenderData *rd = context.getRenderData();

  NodeOutput *outputMask = this->getOutputSocket(0);

  bNode *editorNode = this->getbNode();
  NodeMask *data = (NodeMask *)editorNode->storage;
  Mask *mask = (Mask *)editorNode->id;

  // always connect the output image
  MaskOperation *operation = new MaskOperation();

  if (editorNode->custom1 & CMP_NODEFLAG_MASK_FIXED) {
    operation->setMaskWidth(data->size_x);
    operation->setMaskHeight(data->size_y);
  }
  else if (editorNode->custom1 & CMP_NODEFLAG_MASK_FIXED_SCENE) {
    operation->setMaskWidth(data->size_x * (rd->size / 100.0f));
    operation->setMaskHeight(data->size_y * (rd->size / 100.0f));
  }
  else {
    operation->setMaskWidth(rd->xsch * rd->size / 100.0f);
    operation->setMaskHeight(rd->ysch * rd->size / 100.0f);
  }

  operation->setMask(mask);
  operation->setFramenumber(context.getFramenumber());
  operation->setFeather((bool)(editorNode->custom1 & CMP_NODEFLAG_MASK_NO_FEATHER) == 0);

  if ((editorNode->custom1 & CMP_NODEFLAG_MASK_MOTION_BLUR) && (editorNode->custom2 > 1) &&
      (editorNode->custom3 > FLT_EPSILON)) {
    operation->setMotionBlurSamples(editorNode->custom2);
    operation->setMotionBlurShutter(editorNode->custom3);
  }

  converter.addOperation(operation);
  converter.mapOutputSocket(outputMask, operation->getOutputSocket());
}
