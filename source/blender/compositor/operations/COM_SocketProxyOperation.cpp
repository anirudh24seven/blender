/** Copyright 2011, Blender Foundation.
 */

#include "COM_SocketProxyOperation.h"

SocketProxyOperation::SocketProxyOperation(DataType type, bool use_conversion)
    : NodeOperation(), m_use_conversion(use_conversion)
{
  this->addInputSocket(type);
  this->addOutputSocket(type);
}
