/** \file
 * \ingroup editorui
 */

#pragma once

#include "GPU_texture.h"

#ifdef __cplusplus
extern "C" {
#endif

struct rcti;

struct ColorManagedDisplaySettings;
struct ColorManagedViewSettings;
struct ImBuf;
struct bContext;

typedef struct IMMDrawPixelsTexState {
  struct GPUShader *shader;
  unsigned int pos;
  unsigned int texco;
  bool do_shader_unbind;
} IMMDrawPixelsTexState;

/* To be used before calling immDrawPixelsTex
 * Default shader is GPU_SHADER_2D_IMAGE_COLOR
 * Returns a shader to be able to set uniforms */
IMMDrawPixelsTexState immDrawPixelsTexSetup(int builtin);

/**
 * immDrawPixelsTex - Functions like a limited glDrawPixels, but actually draws the
 * image using textures, which can be tremendously faster on low-end
 * cards, and also avoids problems with the raster position being
 * clipped when offscreen. Pixel unpacking parameters and
 * the glPixelZoom values are _not_ respected.
 *
 * \attention Use immDrawPixelsTexSetup before calling this function.
 *
 * \attention This routine makes many assumptions: the rect data
 * is expected to be in RGBA byte or float format, and the
 * modelview and projection matrices are assumed to define a
 * 1-to-1 mapping to screen space.
 */
void immDrawPixelsTex(IMMDrawPixelsTexState *state,
                      float x,
                      float y,
                      int img_w,
                      int img_h,
                      eGPUTextureFormat gpu_format,
                      bool use_filter,
                      void *rect,
                      float xzoom,
                      float yzoom,
                      const float color[4]);
void immDrawPixelsTex_clipping(IMMDrawPixelsTexState *state,
                               float x,
                               float y,
                               int img_w,
                               int img_h,
                               eGPUTextureFormat gpu_format,
                               bool use_filter,
                               void *rect,
                               float clip_min_x,
                               float clip_min_y,
                               float clip_max_x,
                               float clip_max_y,
                               float xzoom,
                               float yzoom,
                               const float color[4]);
void immDrawPixelsTexScaled(IMMDrawPixelsTexState *state,
                            float x,
                            float y,
                            int img_w,
                            int img_h,
                            eGPUTextureFormat gpu_format,
                            bool use_filter,
                            void *rect,
                            float scaleX,
                            float scaleY,
                            float xzoom,
                            float yzoom,
                            const float color[4]);
void immDrawPixelsTexScaled_clipping(IMMDrawPixelsTexState *state,
                                     float x,
                                     float y,
                                     int img_w,
                                     int img_h,
                                     eGPUTextureFormat gpu_format,
                                     bool use_filter,
                                     void *rect,
                                     float scaleX,
                                     float scaleY,
                                     float clip_min_x,
                                     float clip_min_y,
                                     float clip_max_x,
                                     float clip_max_y,
                                     float xzoom,
                                     float yzoom,
                                     const float color[4]);

/* Image buffer drawing functions, with display transform
 *
 * The view and display settings can either be specified manually,
 * or retrieved from the context with the '_ctx' variations.
 *
 * For better performance clipping coordinates can be specified so parts of the
 * image outside the view are skipped. */

void ED_draw_imbuf(struct ImBuf *ibuf,
                   float x,
                   float y,
                   bool use_filter,
                   struct ColorManagedViewSettings *view_settings,
                   struct ColorManagedDisplaySettings *display_settings,
                   float zoom_x,
                   float zoom_y);
void ED_draw_imbuf_clipping(struct ImBuf *ibuf,
                            float x,
                            float y,
                            bool use_filter,
                            struct ColorManagedViewSettings *view_settings,
                            struct ColorManagedDisplaySettings *display_settings,
                            float clip_min_x,
                            float clip_min_y,
                            float clip_max_x,
                            float clip_max_y,
                            float zoom_x,
                            float zoom_y);

void ED_draw_imbuf_ctx(const struct bContext *C,
                       struct ImBuf *ibuf,
                       float x,
                       float y,
                       bool use_filter,
                       float zoom_x,
                       float zoom_y);
void ED_draw_imbuf_ctx_clipping(const struct bContext *C,
                                struct ImBuf *ibuf,
                                float x,
                                float y,
                                bool use_filter,
                                float clip_min_x,
                                float clip_min_y,
                                float clip_max_x,
                                float clip_max_y,
                                float zoom_x,
                                float zoom_y);

int ED_draw_imbuf_method(struct ImBuf *ibuf);

void immDrawBorderCorners(unsigned int pos, const struct rcti *border, float zoomx, float zoomy);

#ifdef __cplusplus
}
#endif
