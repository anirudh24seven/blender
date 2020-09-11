/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

class SeparateColorNode : public Node {
 public:
  SeparateColorNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;

 protected:
  virtual NodeOperation *getColorConverter(const CompositorContext &context) const = 0;
};

class SeparateRGBANode : public SeparateColorNode {
 public:
  SeparateRGBANode(bNode *editorNode) : SeparateColorNode(editorNode)
  {
  }

  NodeOperation *getColorConverter(const CompositorContext &context) const;
};

class SeparateHSVANode : public SeparateColorNode {
 public:
  SeparateHSVANode(bNode *editorNode) : SeparateColorNode(editorNode)
  {
  }

  NodeOperation *getColorConverter(const CompositorContext &context) const;
};

class SeparateYCCANode : public SeparateColorNode {
 public:
  SeparateYCCANode(bNode *editorNode) : SeparateColorNode(editorNode)
  {
  }

  NodeOperation *getColorConverter(const CompositorContext &context) const;
};

class SeparateYUVANode : public SeparateColorNode {
 public:
  SeparateYUVANode(bNode *editorNode) : SeparateColorNode(editorNode)
  {
  }

  NodeOperation *getColorConverter(const CompositorContext &context) const;
};
