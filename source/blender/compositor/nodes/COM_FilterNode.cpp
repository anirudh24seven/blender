/** Copyright 2011, Blender Foundation.
 */

#include "COM_FilterNode.h"
#include "BKE_node.h"
#include "COM_ConvolutionEdgeFilterOperation.h"
#include "COM_ConvolutionFilterOperation.h"
#include "COM_ExecutionSystem.h"
#include "COM_MixOperation.h"

FilterNode::FilterNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void FilterNode::convertToOperations(NodeConverter &converter,
                                     const CompositorContext & /*context*/) const
{
  NodeInput *inputSocket = this->getInputSocket(0);
  NodeInput *inputImageSocket = this->getInputSocket(1);
  NodeOutput *outputSocket = this->getOutputSocket(0);
  ConvolutionFilterOperation *operation = NULL;

  switch (this->getbNode()->custom1) {
    case CMP_FILT_SOFT:
      operation = new ConvolutionFilterOperation();
      operation->set3x3Filter(1 / 16.0f,
                              2 / 16.0f,
                              1 / 16.0f,
                              2 / 16.0f,
                              4 / 16.0f,
                              2 / 16.0f,
                              1 / 16.0f,
                              2 / 16.0f,
                              1 / 16.0f);
      break;
    case CMP_FILT_SHARP:
      operation = new ConvolutionFilterOperation();
      operation->set3x3Filter(-1, -1, -1, -1, 9, -1, -1, -1, -1);
      break;
    case CMP_FILT_LAPLACE:
      operation = new ConvolutionEdgeFilterOperation();
      operation->set3x3Filter(-1 / 8.0f,
                              -1 / 8.0f,
                              -1 / 8.0f,
                              -1 / 8.0f,
                              1.0f,
                              -1 / 8.0f,
                              -1 / 8.0f,
                              -1 / 8.0f,
                              -1 / 8.0f);
      break;
    case CMP_FILT_SOBEL:
      operation = new ConvolutionEdgeFilterOperation();
      operation->set3x3Filter(1, 2, 1, 0, 0, 0, -1, -2, -1);
      break;
    case CMP_FILT_PREWITT:
      operation = new ConvolutionEdgeFilterOperation();
      operation->set3x3Filter(1, 1, 1, 0, 0, 0, -1, -1, -1);
      break;
    case CMP_FILT_KIRSCH:
      operation = new ConvolutionEdgeFilterOperation();
      operation->set3x3Filter(5, 5, 5, -3, -3, -3, -2, -2, -2);
      break;
    case CMP_FILT_SHADOW:
      operation = new ConvolutionFilterOperation();
      operation->set3x3Filter(1, 2, 1, 0, 1, 0, -1, -2, -1);
      break;
    default:
      operation = new ConvolutionFilterOperation();
      operation->set3x3Filter(0, 0, 0, 0, 1, 0, 0, 0, 0);
      break;
  }
  converter.addOperation(operation);

  converter.mapInputSocket(inputImageSocket, operation->getInputSocket(0));
  converter.mapInputSocket(inputSocket, operation->getInputSocket(1));
  converter.mapOutputSocket(outputSocket, operation->getOutputSocket());

  converter.addPreview(operation->getOutputSocket(0));
}
