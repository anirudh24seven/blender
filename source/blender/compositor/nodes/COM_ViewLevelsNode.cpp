/** Copyright 2011, Blender Foundation.
 */

#include "COM_ViewLevelsNode.h"
#include "COM_CalculateMeanOperation.h"
#include "COM_CalculateStandardDeviationOperation.h"
#include "COM_ExecutionSystem.h"
#include "COM_SetValueOperation.h"

ViewLevelsNode::ViewLevelsNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void ViewLevelsNode::convertToOperations(NodeConverter &converter,
                                         const CompositorContext & /*context*/) const
{
  NodeInput *input = this->getInputSocket(0);
  if (input->isLinked()) {
    // add preview to inputSocket;

    /* calculate mean operation */
    {
      CalculateMeanOperation *operation = new CalculateMeanOperation();
      operation->setSetting(this->getbNode()->custom1);

      converter.addOperation(operation);
      converter.mapInputSocket(input, operation->getInputSocket(0));
      converter.mapOutputSocket(this->getOutputSocket(0), operation->getOutputSocket());
    }

    /* calculate standard deviation operation */
    {
      CalculateStandardDeviationOperation *operation = new CalculateStandardDeviationOperation();
      operation->setSetting(this->getbNode()->custom1);

      converter.addOperation(operation);
      converter.mapInputSocket(input, operation->getInputSocket(0));
      converter.mapOutputSocket(this->getOutputSocket(1), operation->getOutputSocket());
    }
  }
  else {
    converter.addOutputValue(getOutputSocket(0), 0.0f);
    converter.addOutputValue(getOutputSocket(1), 0.0f);
  }
}
