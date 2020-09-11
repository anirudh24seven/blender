/** Copyright 2011, Blender Foundation.
 */

#include "COM_ColorCurveNode.h"
#include "COM_ColorCurveOperation.h"
#include "COM_ExecutionSystem.h"

ColorCurveNode::ColorCurveNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void ColorCurveNode::convertToOperations(NodeConverter &converter,
                                         const CompositorContext & /*context*/) const
{
  if (this->getInputSocket(2)->isLinked() || this->getInputSocket(3)->isLinked()) {
    ColorCurveOperation *operation = new ColorCurveOperation();
    operation->setCurveMapping((CurveMapping *)this->getbNode()->storage);
    converter.addOperation(operation);

    converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
    converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
    converter.mapInputSocket(getInputSocket(2), operation->getInputSocket(2));
    converter.mapInputSocket(getInputSocket(3), operation->getInputSocket(3));

    converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket());
  }
  else {
    ConstantLevelColorCurveOperation *operation = new ConstantLevelColorCurveOperation();
    float col[4];
    this->getInputSocket(2)->getEditorValueColor(col);
    operation->setBlackLevel(col);
    this->getInputSocket(3)->getEditorValueColor(col);
    operation->setWhiteLevel(col);
    operation->setCurveMapping((CurveMapping *)this->getbNode()->storage);
    converter.addOperation(operation);

    converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
    converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
    converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket());
  }
}
