#ifndef OPENSUBDIV_DEVICE_CONTEXT_OPENCL_H_
#define OPENSUBDIV_DEVICE_CONTEXT_OPENCL_H_

namespace blender {
namespace opensubdiv {

class OpenCLDeviceContext {
 public:
  // Stateless check to see whether OpenCL functionality is available on this
  // platform.
  static bool isSupported();

  OpenCLDeviceContext();
  ~OpenCLDeviceContext();
};

}  // namespace opensubdiv
}  // namespace blender

#endif  // _OPENSUBDIV_DEVICE_CONTEXT_OPENCL_H_
