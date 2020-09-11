#include "internal/device/device_context_opencl.h"

namespace blender {
namespace opensubdiv {

bool OpenCLDeviceContext::isSupported()
{
  // TODO(sergey): Add support of OpenCL devices.
  return false;
}

OpenCLDeviceContext::OpenCLDeviceContext()
{
}

OpenCLDeviceContext::~OpenCLDeviceContext()
{
}

}  // namespace opensubdiv
}  // namespace blender
