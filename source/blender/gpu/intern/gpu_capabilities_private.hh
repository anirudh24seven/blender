/** \file
 * \ingroup gpu
 */

#pragma once

#include "GPU_platform.h"

namespace blender::gpu {

/**
 * This includes both hardware capabilities & workarounds.
 * Try to limit these to the implementation codebase (i.e.: gpu/opengl/).
 * Only add workarounds here if they are common to all implementation or
 * if you need access to it outside of the GPU module.
 * Same goes for capabilities (i.e.: texture size)
 **/
struct GPUCapabilities {
  int max_texture_size = 0;
  int max_texture_layers = 0;
  int max_textures = 0;
  int max_textures_vert = 0;
  int max_textures_geom = 0;
  int max_textures_frag = 0;
  bool mem_stats_support = false;
  /* OpenGL related workarounds. */
  bool mip_render_workaround = false;
  bool depth_blitting_workaround = false;
  bool use_main_context_workaround = false;
  bool broken_amd_driver = false;
  /* Vulkan related workarounds. */
};

extern GPUCapabilities GCaps;

}  // namespace blender::gpu