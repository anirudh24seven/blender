/** Copyright 2011, Blender Foundation.
 */

#include "COM_MovieDistortionNode.h"

#include "COM_ExecutionSystem.h"
#include "COM_MovieDistortionOperation.h"
#include "DNA_movieclip_types.h"

MovieDistortionNode::MovieDistortionNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void MovieDistortionNode::convertToOperations(NodeConverter &converter,
                                              const CompositorContext &context) const
{
  bNode *bnode = this->getbNode();
  MovieClip *clip = (MovieClip *)bnode->id;

  NodeInput *inputSocket = this->getInputSocket(0);
  NodeOutput *outputSocket = this->getOutputSocket(0);

  MovieDistortionOperation *operation = new MovieDistortionOperation(bnode->custom1 == 1);
  operation->setMovieClip(clip);
  operation->setFramenumber(context.getFramenumber());
  converter.addOperation(operation);

  converter.mapInputSocket(inputSocket, operation->getInputSocket(0));
  converter.mapOutputSocket(outputSocket, operation->getOutputSocket(0));
}
