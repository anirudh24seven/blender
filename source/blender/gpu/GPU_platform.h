/** \file
 * \ingroup gpu
 */

#pragma once

#include "BLI_sys_types.h"
#include "BLI_utildefines.h"

/* GPU platform support */

/* GPU Types */
typedef enum eGPUDeviceType {
  GPU_DEVICE_NVIDIA = (1 << 0),
  GPU_DEVICE_ATI = (1 << 1),
  GPU_DEVICE_INTEL = (1 << 2),
  GPU_DEVICE_INTEL_UHD = (1 << 3),
  GPU_DEVICE_SOFTWARE = (1 << 4),
  GPU_DEVICE_UNKNOWN = (1 << 5),
  GPU_DEVICE_ANY = (0xff),
} eGPUDeviceType;

ENUM_OPERATORS(eGPUDeviceType)

typedef enum eGPUOSType {
  GPU_OS_WIN = (1 << 8),
  GPU_OS_MAC = (1 << 9),
  GPU_OS_UNIX = (1 << 10),
  GPU_OS_ANY = (0xff00),
} eGPUOSType;

typedef enum eGPUDriverType {
  GPU_DRIVER_OFFICIAL = (1 << 16),
  GPU_DRIVER_OPENSOURCE = (1 << 17),
  GPU_DRIVER_SOFTWARE = (1 << 18),
  GPU_DRIVER_ANY = (0xff0000),
} eGPUDriverType;

typedef enum eGPUSupportLevel {
  GPU_SUPPORT_LEVEL_SUPPORTED,
  GPU_SUPPORT_LEVEL_LIMITED,
  GPU_SUPPORT_LEVEL_UNSUPPORTED,
} eGPUSupportLevel;

#ifdef __cplusplus
extern "C" {
#endif

bool GPU_type_matches(eGPUDeviceType device, eGPUOSType os, eGPUDriverType driver);
eGPUSupportLevel GPU_platform_support_level(void);
const char *GPU_platform_support_level_key(void);
const char *GPU_platform_gpu_name(void);

#ifdef __cplusplus
}
#endif
