/** Copyright 2011, Blender Foundation.
 */

#include "COM_SplitViewerNode.h"
#include "BKE_global.h"
#include "BKE_image.h"
#include "BKE_scene.h"

#include "COM_ExecutionSystem.h"
#include "COM_SplitOperation.h"
#include "COM_ViewerOperation.h"

SplitViewerNode::SplitViewerNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void SplitViewerNode::convertToOperations(NodeConverter &converter,
                                          const CompositorContext &context) const
{
  bNode *editorNode = this->getbNode();
  bool do_output = (editorNode->flag & NODE_DO_OUTPUT_RECALC || context.isRendering()) &&
                   (editorNode->flag & NODE_DO_OUTPUT);

  NodeInput *image1Socket = this->getInputSocket(0);
  NodeInput *image2Socket = this->getInputSocket(1);
  Image *image = (Image *)this->getbNode()->id;
  ImageUser *imageUser = (ImageUser *)this->getbNode()->storage;

  SplitOperation *splitViewerOperation = new SplitOperation();
  splitViewerOperation->setSplitPercentage(this->getbNode()->custom1);
  splitViewerOperation->setXSplit(!this->getbNode()->custom2);

  converter.addOperation(splitViewerOperation);
  converter.mapInputSocket(image1Socket, splitViewerOperation->getInputSocket(0));
  converter.mapInputSocket(image2Socket, splitViewerOperation->getInputSocket(1));

  ViewerOperation *viewerOperation = new ViewerOperation();
  viewerOperation->setImage(image);
  viewerOperation->setImageUser(imageUser);
  viewerOperation->setViewSettings(context.getViewSettings());
  viewerOperation->setDisplaySettings(context.getDisplaySettings());
  viewerOperation->setRenderData(context.getRenderData());
  viewerOperation->setViewName(context.getViewName());

  /* defaults - the viewer node has these options but not exposed for split view
   * we could use the split to define an area of interest on one axis at least */
  viewerOperation->setChunkOrder(COM_ORDER_OF_CHUNKS_DEFAULT);
  viewerOperation->setCenterX(0.5f);
  viewerOperation->setCenterY(0.5f);

  converter.addOperation(viewerOperation);
  converter.addLink(splitViewerOperation->getOutputSocket(), viewerOperation->getInputSocket(0));

  converter.addPreview(splitViewerOperation->getOutputSocket());

  if (do_output) {
    converter.registerViewer(viewerOperation);
  }
}
