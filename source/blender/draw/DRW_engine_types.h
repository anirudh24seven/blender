/** \file
 * \ingroup draw
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* Buffer and textures used by the viewport by default */
typedef struct DefaultFramebufferList {
  struct GPUFrameBuffer *default_fb;
  struct GPUFrameBuffer *overlay_fb;
  struct GPUFrameBuffer *in_front_fb;
  struct GPUFrameBuffer *color_only_fb;
  struct GPUFrameBuffer *depth_only_fb;
  struct GPUFrameBuffer *overlay_only_fb;
  struct GPUFrameBuffer *stereo_comp_fb;
} DefaultFramebufferList;

typedef struct DefaultTextureList {
  struct GPUTexture *color;
  struct GPUTexture *color_overlay;
  struct GPUTexture *color_stereo;
  struct GPUTexture *color_overlay_stereo;
  struct GPUTexture *depth;
  struct GPUTexture *depth_in_front;
} DefaultTextureList;

#ifdef __cplusplus
}
#endif
