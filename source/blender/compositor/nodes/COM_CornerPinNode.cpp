#include "COM_CornerPinNode.h"
#include "COM_ExecutionSystem.h"

#include "COM_PlaneCornerPinOperation.h"

CornerPinNode::CornerPinNode(bNode *editorNode) : Node(editorNode)
{
}

void CornerPinNode::convertToOperations(NodeConverter &converter,
                                        const CompositorContext & /*context*/) const
{
  NodeInput *input_image = this->getInputSocket(0);
  /* note: socket order differs between UI node and operations:
   * bNode uses intuitive order following top-down layout:
   *   upper-left, upper-right, lower-left, lower-right
   * Operations use same order as the tracking blenkernel functions expect:
   *   lower-left, lower-right, upper-right, upper-left
   */
  const int node_corner_index[4] = {3, 4, 2, 1};

  NodeOutput *output_warped_image = this->getOutputSocket(0);
  NodeOutput *output_plane = this->getOutputSocket(1);

  PlaneCornerPinWarpImageOperation *warp_image_operation = new PlaneCornerPinWarpImageOperation();
  converter.addOperation(warp_image_operation);
  PlaneCornerPinMaskOperation *plane_mask_operation = new PlaneCornerPinMaskOperation();
  converter.addOperation(plane_mask_operation);

  converter.mapInputSocket(input_image, warp_image_operation->getInputSocket(0));
  for (int i = 0; i < 4; i++) {
    NodeInput *corner_input = getInputSocket(node_corner_index[i]);
    converter.mapInputSocket(corner_input, warp_image_operation->getInputSocket(i + 1));
    converter.mapInputSocket(corner_input, plane_mask_operation->getInputSocket(i));
  }
  converter.mapOutputSocket(output_warped_image, warp_image_operation->getOutputSocket());
  converter.mapOutputSocket(output_plane, plane_mask_operation->getOutputSocket());
}
