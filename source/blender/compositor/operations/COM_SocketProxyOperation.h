/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class SocketProxyOperation : public NodeOperation {
 public:
  SocketProxyOperation(DataType type, bool use_conversion);

  bool isProxyOperation() const
  {
    return true;
  }
  bool useDatatypeConversion() const
  {
    return m_use_conversion;
  }

  bool getUseConversion() const
  {
    return m_use_conversion;
  }
  void setUseConversion(bool use_conversion)
  {
    m_use_conversion = use_conversion;
  }

 private:
  bool m_use_conversion;
};
