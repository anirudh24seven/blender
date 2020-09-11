/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief KeyingNode
 * \ingroup Node
 */
class KeyingNode : public Node {
 protected:
  NodeOperationOutput *setupPreBlur(NodeConverter &converter,
                                    NodeInput *inputImage,
                                    int size) const;
  NodeOperationOutput *setupPostBlur(NodeConverter &converter,
                                     NodeOperationOutput *postBlurInput,
                                     int size) const;
  NodeOperationOutput *setupDilateErode(NodeConverter &converter,
                                        NodeOperationOutput *dilateErodeInput,
                                        int distance) const;
  NodeOperationOutput *setupFeather(NodeConverter &converter,
                                    const CompositorContext &context,
                                    NodeOperationOutput *featherInput,
                                    int falloff,
                                    int distance) const;
  NodeOperationOutput *setupDespill(NodeConverter &converter,
                                    NodeOperationOutput *despillInput,
                                    NodeInput *inputScreen,
                                    float factor,
                                    float colorBalance) const;
  NodeOperationOutput *setupClip(NodeConverter &converter,
                                 NodeOperationOutput *clipInput,
                                 int kernelRadius,
                                 float kernelTolerance,
                                 float clipBlack,
                                 float clipWhite,
                                 bool edgeMatte) const;

 public:
  KeyingNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
