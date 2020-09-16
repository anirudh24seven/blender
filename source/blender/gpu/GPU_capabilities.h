/** \file
 * \ingroup gpu
 *
 * GPU Capabilities & workarounds
 * This module expose the reported implementation limits & enabled
 * workaround for drivers that needs specific codepaths.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

int GPU_max_texture_size(void);
int GPU_max_texture_layers(void);
int GPU_max_textures(void);
int GPU_max_textures_vert(void);
int GPU_max_textures_geom(void);
int GPU_max_textures_frag(void);

int GPU_texture_size_with_limit(int res);

bool GPU_mip_render_workaround(void);
bool GPU_depth_blitting_workaround(void);
bool GPU_use_main_context_workaround(void);
bool GPU_crappy_amd_driver(void);

bool GPU_shader_image_load_store_support(void);

bool GPU_mem_stats_supported(void);
void GPU_mem_stats_get(int *totalmem, int *freemem);

bool GPU_stereo_quadbuffer_support(void);

#ifdef __cplusplus
}
#endif
