/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Node.h"

/**
 * \brief SocketProxyNode
 * \ingroup Node
 */
class SocketProxyNode : public Node {
 public:
  SocketProxyNode(bNode *editorNode,
                  bNodeSocket *editorInput,
                  bNodeSocket *editorOutput,
                  bool use_conversion);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;

  bool getUseConversion() const
  {
    return m_use_conversion;
  }
  void setUseConversion(bool use_conversion)
  {
    m_use_conversion = use_conversion;
  }

 private:
  /** If true, the proxy will convert input and output data to/from the proxy socket types. */
  bool m_use_conversion;
};

class SocketBufferNode : public Node {
 public:
  SocketBufferNode(bNode *editorNode, bNodeSocket *editorInput, bNodeSocket *editorOutput);
  void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};
