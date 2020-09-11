#include "internal/device/device_context_openmp.h"

namespace blender {
namespace opensubdiv {

bool OpenMPDeviceContext::isSupported()
{
#ifdef OPENSUBDIV_HAS_OPENMP
  return true;
#else
  return false;
#endif
}

OpenMPDeviceContext::OpenMPDeviceContext()
{
}

OpenMPDeviceContext::~OpenMPDeviceContext()
{
}

}  // namespace opensubdiv
}  // namespace blender
