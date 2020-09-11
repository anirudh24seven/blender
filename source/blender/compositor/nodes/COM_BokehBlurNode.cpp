/** Copyright 2011, Blender Foundation.
 */

#include "COM_BokehBlurNode.h"
#include "COM_BokehBlurOperation.h"
#include "COM_ConvertDepthToRadiusOperation.h"
#include "COM_ExecutionSystem.h"
#include "COM_VariableSizeBokehBlurOperation.h"
#include "DNA_camera_types.h"
#include "DNA_node_types.h"
#include "DNA_object_types.h"

BokehBlurNode::BokehBlurNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void BokehBlurNode::convertToOperations(NodeConverter &converter,
                                        const CompositorContext &context) const
{
  bNode *b_node = this->getbNode();

  NodeInput *inputSizeSocket = this->getInputSocket(2);

  bool connectedSizeSocket = inputSizeSocket->isLinked();
  const bool extend_bounds = (b_node->custom1 & CMP_NODEFLAG_BLUR_EXTEND_BOUNDS) != 0;

  if ((b_node->custom1 & CMP_NODEFLAG_BLUR_VARIABLE_SIZE) && connectedSizeSocket) {
    VariableSizeBokehBlurOperation *operation = new VariableSizeBokehBlurOperation();
    operation->setQuality(context.getQuality());
    operation->setThreshold(0.0f);
    operation->setMaxBlur(b_node->custom4);
    operation->setDoScaleSize(true);

    converter.addOperation(operation);
    converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
    converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
    converter.mapInputSocket(getInputSocket(2), operation->getInputSocket(2));
    converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket());
  }
  else {
    BokehBlurOperation *operation = new BokehBlurOperation();
    operation->setQuality(context.getQuality());
    operation->setExtendBounds(extend_bounds);

    converter.addOperation(operation);
    converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
    converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));

    // NOTE: on the bokeh blur operation the sockets are switched.
    // for this reason the next two lines are correct.
    // Fix for T43771
    converter.mapInputSocket(getInputSocket(2), operation->getInputSocket(3));
    converter.mapInputSocket(getInputSocket(3), operation->getInputSocket(2));

    converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket());

    if (!connectedSizeSocket) {
      operation->setSize(this->getInputSocket(2)->getEditorValueFloat());
    }
  }
}
