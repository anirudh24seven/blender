#include "internal/device/device_context_glsl_transform_feedback.h"

#include <GL/glew.h>

namespace blender {
namespace opensubdiv {

bool GLSLTransformFeedbackDeviceContext::isSupported()
{
  return GLEW_VERSION_4_1;
}

GLSLTransformFeedbackDeviceContext::GLSLTransformFeedbackDeviceContext()
{
}

GLSLTransformFeedbackDeviceContext::~GLSLTransformFeedbackDeviceContext()
{
}

}  // namespace opensubdiv
}  // namespace blender
