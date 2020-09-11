#ifndef OPENSUBDIV_DEVICE_CONTEXT_GLSL_COMPUTE_H_
#define OPENSUBDIV_DEVICE_CONTEXT_GLSL_COMPUTE_H_

namespace blender {
namespace opensubdiv {

class GLSLComputeDeviceContext {
 public:
  // Stateless check to see whether GLSL compute functionality is
  // available on this platform.
  static bool isSupported();

  GLSLComputeDeviceContext();
  ~GLSLComputeDeviceContext();
};

}  // namespace opensubdiv
}  // namespace blender

#endif  // _OPENSUBDIV_DEVICE_CONTEXT_GLSL_COMPUTE_H_
