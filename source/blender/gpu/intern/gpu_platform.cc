/** \file
 * \ingroup gpu
 *
 * Wrap OpenGL features such as textures, shaders and GLSL
 * with checks for drivers and GPU support.
 */

#include "MEM_guardedalloc.h"

#include "BLI_dynstr.h"
#include "BLI_string.h"

#include "GPU_platform.h"

#include "gpu_platform_private.hh"

/* -------------------------------------------------------------------- */
/** \name GPUPlatformGlobal
 * \{ */

namespace blender::gpu {

GPUPlatformGlobal GPG;

void GPUPlatformGlobal::create_key(eGPUSupportLevel support_level,
                                   const char *vendor,
                                   const char *renderer,
                                   const char *version)
{
  DynStr *ds = BLI_dynstr_new();
  BLI_dynstr_appendf(ds, "{%s/%s/%s}=", vendor, renderer, version);
  if (support_level == GPU_SUPPORT_LEVEL_SUPPORTED) {
    BLI_dynstr_append(ds, "SUPPORTED");
  }
  else if (support_level == GPU_SUPPORT_LEVEL_LIMITED) {
    BLI_dynstr_append(ds, "LIMITED");
  }
  else {
    BLI_dynstr_append(ds, "UNSUPPORTED");
  }

  support_key = BLI_dynstr_get_cstring(ds);
  BLI_dynstr_free(ds);
  BLI_str_replace_char(support_key, '\n', ' ');
  BLI_str_replace_char(support_key, '\r', ' ');
}

void GPUPlatformGlobal::create_gpu_name(const char *vendor,
                                        const char *renderer,
                                        const char *version)
{
  DynStr *ds = BLI_dynstr_new();
  BLI_dynstr_appendf(ds, "%s %s %s", vendor, renderer, version);

  gpu_name = BLI_dynstr_get_cstring(ds);
  BLI_dynstr_free(ds);
  BLI_str_replace_char(gpu_name, '\n', ' ');
  BLI_str_replace_char(gpu_name, '\r', ' ');
}

void GPUPlatformGlobal::clear(void)
{
  MEM_SAFE_FREE(GPG.support_key);
  MEM_SAFE_FREE(GPG.gpu_name);
  initialized = false;
}

}  // namespace blender::gpu

/** \} */

/* -------------------------------------------------------------------- */
/** \name C-API
 * \{ */

using namespace blender::gpu;

eGPUSupportLevel GPU_platform_support_level(void)
{
  return GPG.support_level;
}

const char *GPU_platform_support_level_key(void)
{
  return GPG.support_key;
}

const char *GPU_platform_gpu_name(void)
{
  return GPG.gpu_name;
}

/* GPU Types */
bool GPU_type_matches(eGPUDeviceType device, eGPUOSType os, eGPUDriverType driver)
{
  return (GPG.device & device) && (GPG.os & os) && (GPG.driver & driver);
}

/** \} */