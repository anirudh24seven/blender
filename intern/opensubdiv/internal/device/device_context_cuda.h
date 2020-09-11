#ifndef OPENSUBDIV_DEVICE_CONTEXT_CUDA_H_
#define OPENSUBDIV_DEVICE_CONTEXT_CUDA_H_

namespace blender {
namespace opensubdiv {

class CUDADeviceContext {
 public:
  // Stateless check to see whether CUDA functionality is available on this
  // platform.
  static bool isSupported();

  CUDADeviceContext();
  ~CUDADeviceContext();
};

}  // namespace opensubdiv
}  // namespace blender

#endif  // _OPENSUBDIV_DEVICE_CONTEXT_CUDA_H_
