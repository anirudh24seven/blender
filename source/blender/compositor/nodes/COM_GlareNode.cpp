/** Copyright 2011, Blender Foundation.
 */

#include "COM_GlareNode.h"
#include "COM_FastGaussianBlurOperation.h"
#include "COM_GlareFogGlowOperation.h"
#include "COM_GlareGhostOperation.h"
#include "COM_GlareSimpleStarOperation.h"
#include "COM_GlareStreaksOperation.h"
#include "COM_GlareThresholdOperation.h"
#include "COM_MixOperation.h"
#include "COM_SetValueOperation.h"
#include "DNA_node_types.h"

GlareNode::GlareNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void GlareNode::convertToOperations(NodeConverter &converter,
                                    const CompositorContext & /*context*/) const
{
  bNode *node = this->getbNode();
  NodeGlare *glare = (NodeGlare *)node->storage;

  GlareBaseOperation *glareoperation = NULL;
  switch (glare->type) {
    default:
    case 3:
      glareoperation = new GlareGhostOperation();
      break;
    case 2:  // streaks
      glareoperation = new GlareStreaksOperation();
      break;
    case 1:  // fog glow
      glareoperation = new GlareFogGlowOperation();
      break;
    case 0:  // simple star
      glareoperation = new GlareSimpleStarOperation();
      break;
  }
  BLI_assert(glareoperation);
  glareoperation->setGlareSettings(glare);

  GlareThresholdOperation *thresholdOperation = new GlareThresholdOperation();
  thresholdOperation->setGlareSettings(glare);

  SetValueOperation *mixvalueoperation = new SetValueOperation();
  mixvalueoperation->setValue(0.5f + glare->mix * 0.5f);

  MixGlareOperation *mixoperation = new MixGlareOperation();
  mixoperation->setResolutionInputSocketIndex(1);
  mixoperation->getInputSocket(2)->setResizeMode(COM_SC_FIT);

  converter.addOperation(glareoperation);
  converter.addOperation(thresholdOperation);
  converter.addOperation(mixvalueoperation);
  converter.addOperation(mixoperation);

  converter.mapInputSocket(getInputSocket(0), thresholdOperation->getInputSocket(0));
  converter.addLink(thresholdOperation->getOutputSocket(), glareoperation->getInputSocket(0));

  converter.addLink(mixvalueoperation->getOutputSocket(), mixoperation->getInputSocket(0));
  converter.mapInputSocket(getInputSocket(0), mixoperation->getInputSocket(1));
  converter.addLink(glareoperation->getOutputSocket(), mixoperation->getInputSocket(2));
  converter.mapOutputSocket(getOutputSocket(), mixoperation->getOutputSocket());
}
