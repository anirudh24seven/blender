/** Copyright 2020, Blender Foundation.
 */

/** \file
 * \ingroup draw_engine
 */

#include "DRW_render.h"

#include "BLI_dynstr.h"

#include "GPU_batch.h"

#include "image_engine.h"
#include "image_private.h"

extern char datatoc_common_colormanagement_lib_glsl[];
extern char datatoc_common_globals_lib_glsl[];
extern char datatoc_common_view_lib_glsl[];

extern char datatoc_engine_image_frag_glsl[];
extern char datatoc_engine_image_vert_glsl[];

typedef struct IMAGE_Shaders {
  GPUShader *image_sh;
} IMAGE_Shaders;

static struct {
  IMAGE_Shaders shaders;
  DRWShaderLibrary *lib;
} e_data = {0}; /* Engine data */

void IMAGE_shader_library_ensure(void)
{
  if (e_data.lib == NULL) {
    e_data.lib = DRW_shader_library_create();
    /* NOTE: Theses needs to be ordered by dependencies. */
    DRW_SHADER_LIB_ADD(e_data.lib, common_colormanagement_lib);
    DRW_SHADER_LIB_ADD(e_data.lib, common_globals_lib);
    DRW_SHADER_LIB_ADD(e_data.lib, common_view_lib);
  }
}

GPUShader *IMAGE_shader_image_get(void)
{
  IMAGE_Shaders *sh_data = &e_data.shaders;
  if (!sh_data->image_sh) {
    sh_data->image_sh = DRW_shader_create_with_shaderlib(
        datatoc_engine_image_vert_glsl, NULL, datatoc_engine_image_frag_glsl, e_data.lib, NULL);
  }
  return sh_data->image_sh;
}

void IMAGE_shader_free(void)
{
  GPUShader **sh_data_as_array = (GPUShader **)&e_data.shaders;
  for (int i = 0; i < (sizeof(IMAGE_Shaders) / sizeof(GPUShader *)); i++) {
    DRW_SHADER_FREE_SAFE(sh_data_as_array[i]);
  }

  DRW_SHADER_LIB_FREE_SAFE(e_data.lib);
}