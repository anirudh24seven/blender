#ifndef OPENSUBDIV_DEVICE_CONTEXT_GLSL_TRANSFORM_FEEDBACK_H_
#define OPENSUBDIV_DEVICE_CONTEXT_GLSL_TRANSFORM_FEEDBACK_H_

namespace blender {
namespace opensubdiv {

class GLSLTransformFeedbackDeviceContext {
 public:
  // Stateless check to see whether GLSL transform feedback functionality is
  // available on this platform.
  static bool isSupported();

  GLSLTransformFeedbackDeviceContext();
  ~GLSLTransformFeedbackDeviceContext();
};

}  // namespace opensubdiv
}  // namespace blender

#endif  // _OPENSUBDIV_DEVICE_CONTEXT_GLSL_TRANSFORM_FEEDBACK_H_
