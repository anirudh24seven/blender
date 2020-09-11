#ifndef OPENSUBDIV_DEVICE_CONTEXT_OPENMP_H_
#define OPENSUBDIV_DEVICE_CONTEXT_OPENMP_H_

namespace blender {
namespace opensubdiv {

class OpenMPDeviceContext {
 public:
  // Stateless check to see whether OpenMP functionality is available on this
  // platform.
  static bool isSupported();

  OpenMPDeviceContext();
  ~OpenMPDeviceContext();
};

}  // namespace opensubdiv
}  // namespace blender

#endif  // _OPENSUBDIV_DEVICE_CONTEXT_OPENMP_H_
