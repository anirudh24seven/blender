/** Copyright 2011, Blender Foundation.
 */

#include <string.h>

#include "BKE_node.h"

#include "RNA_access.h"

#include "COM_ExecutionSystem.h"
#include "COM_NodeOperation.h"
#include "COM_TranslateOperation.h"

#include "COM_SocketProxyNode.h"

#include "COM_defines.h"

#include "COM_Node.h" /* own include */

/**************
 **** Node ****
 **************/

Node::Node(bNode *editorNode, bool create_sockets)
    : m_editorNodeTree(NULL),
      m_editorNode(editorNode),
      m_inActiveGroup(false),
      m_instanceKey(NODE_INSTANCE_KEY_NONE)
{
  if (create_sockets) {
    bNodeSocket *input = (bNodeSocket *)editorNode->inputs.first;
    while (input != NULL) {
      DataType dt = COM_DT_VALUE;
      if (input->type == SOCK_RGBA) {
        dt = COM_DT_COLOR;
      }
      if (input->type == SOCK_VECTOR) {
        dt = COM_DT_VECTOR;
      }

      this->addInputSocket(dt, input);
      input = input->next;
    }
    bNodeSocket *output = (bNodeSocket *)editorNode->outputs.first;
    while (output != NULL) {
      DataType dt = COM_DT_VALUE;
      if (output->type == SOCK_RGBA) {
        dt = COM_DT_COLOR;
      }
      if (output->type == SOCK_VECTOR) {
        dt = COM_DT_VECTOR;
      }

      this->addOutputSocket(dt, output);
      output = output->next;
    }
  }
}

Node::~Node()
{
  while (!this->m_outputsockets.empty()) {
    delete (this->m_outputsockets.back());
    this->m_outputsockets.pop_back();
  }
  while (!this->m_inputsockets.empty()) {
    delete (this->m_inputsockets.back());
    this->m_inputsockets.pop_back();
  }
}

void Node::addInputSocket(DataType datatype)
{
  this->addInputSocket(datatype, NULL);
}

void Node::addInputSocket(DataType datatype, bNodeSocket *bSocket)
{
  NodeInput *socket = new NodeInput(this, bSocket, datatype);
  this->m_inputsockets.push_back(socket);
}

void Node::addOutputSocket(DataType datatype)
{
  this->addOutputSocket(datatype, NULL);
}
void Node::addOutputSocket(DataType datatype, bNodeSocket *bSocket)
{
  NodeOutput *socket = new NodeOutput(this, bSocket, datatype);
  this->m_outputsockets.push_back(socket);
}

NodeOutput *Node::getOutputSocket(unsigned int index) const
{
  BLI_assert(index < this->m_outputsockets.size());
  return this->m_outputsockets[index];
}

NodeInput *Node::getInputSocket(unsigned int index) const
{
  BLI_assert(index < this->m_inputsockets.size());
  return this->m_inputsockets[index];
}

bNodeSocket *Node::getEditorInputSocket(int editorNodeInputSocketIndex)
{
  bNodeSocket *bSock = (bNodeSocket *)this->getbNode()->inputs.first;
  int index = 0;
  while (bSock != NULL) {
    if (index == editorNodeInputSocketIndex) {
      return bSock;
    }
    index++;
    bSock = bSock->next;
  }
  return NULL;
}
bNodeSocket *Node::getEditorOutputSocket(int editorNodeOutputSocketIndex)
{
  bNodeSocket *bSock = (bNodeSocket *)this->getbNode()->outputs.first;
  int index = 0;
  while (bSock != NULL) {
    if (index == editorNodeOutputSocketIndex) {
      return bSock;
    }
    index++;
    bSock = bSock->next;
  }
  return NULL;
}

/*******************
 **** NodeInput ****
 *******************/

NodeInput::NodeInput(Node *node, bNodeSocket *b_socket, DataType datatype)
    : m_node(node), m_editorSocket(b_socket), m_datatype(datatype), m_link(NULL)
{
}

void NodeInput::setLink(NodeOutput *link)
{
  m_link = link;
}

float NodeInput::getEditorValueFloat()
{
  PointerRNA ptr;
  RNA_pointer_create((ID *)getNode()->getbNodeTree(), &RNA_NodeSocket, getbNodeSocket(), &ptr);
  return RNA_float_get(&ptr, "default_value");
}

void NodeInput::getEditorValueColor(float *value)
{
  PointerRNA ptr;
  RNA_pointer_create((ID *)getNode()->getbNodeTree(), &RNA_NodeSocket, getbNodeSocket(), &ptr);
  return RNA_float_get_array(&ptr, "default_value", value);
}

void NodeInput::getEditorValueVector(float *value)
{
  PointerRNA ptr;
  RNA_pointer_create((ID *)getNode()->getbNodeTree(), &RNA_NodeSocket, getbNodeSocket(), &ptr);
  return RNA_float_get_array(&ptr, "default_value", value);
}

/********************
 **** NodeOutput ****
 ********************/

NodeOutput::NodeOutput(Node *node, bNodeSocket *b_socket, DataType datatype)
    : m_node(node), m_editorSocket(b_socket), m_datatype(datatype)
{
}

float NodeOutput::getEditorValueFloat()
{
  PointerRNA ptr;
  RNA_pointer_create((ID *)getNode()->getbNodeTree(), &RNA_NodeSocket, getbNodeSocket(), &ptr);
  return RNA_float_get(&ptr, "default_value");
}

void NodeOutput::getEditorValueColor(float *value)
{
  PointerRNA ptr;
  RNA_pointer_create((ID *)getNode()->getbNodeTree(), &RNA_NodeSocket, getbNodeSocket(), &ptr);
  return RNA_float_get_array(&ptr, "default_value", value);
}

void NodeOutput::getEditorValueVector(float *value)
{
  PointerRNA ptr;
  RNA_pointer_create((ID *)getNode()->getbNodeTree(), &RNA_NodeSocket, getbNodeSocket(), &ptr);
  return RNA_float_get_array(&ptr, "default_value", value);
}
