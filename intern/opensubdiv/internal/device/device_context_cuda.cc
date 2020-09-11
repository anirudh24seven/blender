#include "internal/device/device_context_cuda.h"

namespace blender {
namespace opensubdiv {

bool CUDADeviceContext::isSupported()
{
  // TODO(sergey): Add CUDA device support, using CUDA-RT API.
  return false;
}

CUDADeviceContext::CUDADeviceContext()
{
}

CUDADeviceContext::~CUDADeviceContext()
{
}

}  // namespace opensubdiv
}  // namespace blender
