/** Copyright 2012, Blender Foundation.
 */

#include "COM_KeyingScreenNode.h"
#include "COM_ExecutionSystem.h"
#include "COM_KeyingScreenOperation.h"

#include "DNA_movieclip_types.h"

KeyingScreenNode::KeyingScreenNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void KeyingScreenNode::convertToOperations(NodeConverter &converter,
                                           const CompositorContext &context) const
{
  bNode *editorNode = this->getbNode();
  MovieClip *clip = (MovieClip *)editorNode->id;
  NodeKeyingScreenData *keyingscreen_data = (NodeKeyingScreenData *)editorNode->storage;

  NodeOutput *outputScreen = this->getOutputSocket(0);

  // always connect the output image
  KeyingScreenOperation *operation = new KeyingScreenOperation();
  operation->setMovieClip(clip);
  operation->setTrackingObject(keyingscreen_data->tracking_object);
  operation->setFramenumber(context.getFramenumber());
  converter.addOperation(operation);

  converter.mapOutputSocket(outputScreen, operation->getOutputSocket());
}
