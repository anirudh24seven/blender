/** \file
 * \ingroup gpu
 */

#pragma once

#include "GPU_platform.h"

namespace blender::gpu {

class GPUPlatformGlobal {
 public:
  bool initialized = false;
  eGPUDeviceType device;
  eGPUOSType os;
  eGPUDriverType driver;
  eGPUSupportLevel support_level;
  char *support_key = nullptr;
  char *gpu_name = nullptr;

 public:
  void create_key(eGPUSupportLevel support_level,
                  const char *vendor,
                  const char *renderer,
                  const char *version);

  void create_gpu_name(const char *vendor, const char *renderer, const char *version);

  void clear(void);
};

extern GPUPlatformGlobal GPG;

}  // namespace blender::gpu