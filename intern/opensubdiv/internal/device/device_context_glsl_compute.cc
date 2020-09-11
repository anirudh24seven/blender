#include "internal/device/device_context_glsl_compute.h"

#include <GL/glew.h>

namespace blender {
namespace opensubdiv {

bool GLSLComputeDeviceContext::isSupported()
{
  return GLEW_VERSION_4_3 || GLEW_ARB_compute_shader;
}

GLSLComputeDeviceContext::GLSLComputeDeviceContext()
{
}

GLSLComputeDeviceContext::~GLSLComputeDeviceContext()
{
}

}  // namespace opensubdiv
}  // namespace blender
