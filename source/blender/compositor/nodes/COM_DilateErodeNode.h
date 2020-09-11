/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief DilateErodeNode
 * \ingroup Node
 */
class DilateErodeNode : public Node {
  /** only used for blurring alpha, since the dilate/erode node doesn't have this. */
  NodeBlurData m_alpha_blur;

 public:
  DilateErodeNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
