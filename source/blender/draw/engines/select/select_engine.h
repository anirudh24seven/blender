/** \file
 * \ingroup draw_engine
 */

#pragma once

extern DrawEngineType draw_engine_select_type;
extern RenderEngineType DRW_engine_viewport_select_type;

struct SELECTID_Context *DRW_select_engine_context_get(void);

struct GPUFrameBuffer *DRW_engine_select_framebuffer_get(void);
struct GPUTexture *DRW_engine_select_texture_get(void);
