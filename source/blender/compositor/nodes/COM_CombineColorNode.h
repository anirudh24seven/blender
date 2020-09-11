/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

class CombineColorNode : public Node {
 public:
  CombineColorNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;

 protected:
  virtual NodeOperation *getColorConverter(const CompositorContext &context) const = 0;
};

class CombineRGBANode : public CombineColorNode {
 public:
  CombineRGBANode(bNode *editorNode) : CombineColorNode(editorNode)
  {
  }

  NodeOperation *getColorConverter(const CompositorContext &context) const;
};

class CombineHSVANode : public CombineColorNode {
 public:
  CombineHSVANode(bNode *editorNode) : CombineColorNode(editorNode)
  {
  }

  NodeOperation *getColorConverter(const CompositorContext &context) const;
};

class CombineYCCANode : public CombineColorNode {
 public:
  CombineYCCANode(bNode *editorNode) : CombineColorNode(editorNode)
  {
  }

  NodeOperation *getColorConverter(const CompositorContext &context) const;
};

class CombineYUVANode : public CombineColorNode {
 public:
  CombineYUVANode(bNode *editorNode) : CombineColorNode(editorNode)
  {
  }

  NodeOperation *getColorConverter(const CompositorContext &context) const;
};
