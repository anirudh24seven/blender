/** The Original Code is Copyright (C) 2006 Blender Foundation
 * All rights reserved.
 */

/** \file
 * \ingroup openexr
 */

#pragma once

/* experiment with more advanced exr api */

/* XXX layer+pass name max 64? */
/* This api also supports max 8 channels per pass now. easy to fix! */
#define EXR_LAY_MAXNAME 64
#define EXR_PASS_MAXNAME 64
#define EXR_VIEW_MAXNAME 64
#define EXR_TOT_MAXNAME 64
#define EXR_PASS_MAXCHAN 24

#ifdef __cplusplus
extern "C" {
#endif

struct StampData;

void *IMB_exr_get_handle(void);
void *IMB_exr_get_handle_name(const char *name);
void IMB_exr_add_channel(void *handle,
                         const char *layname,
                         const char *passname,
                         const char *view,
                         int xstride,
                         int ystride,
                         float *rect,
                         bool use_half_float);

int IMB_exr_begin_read(void *handle, const char *filename, int *width, int *height);
int IMB_exr_begin_write(void *handle,
                        const char *filename,
                        int width,
                        int height,
                        int compress,
                        const struct StampData *stamp);
void IMB_exrtile_begin_write(
    void *handle, const char *filename, int mipmap, int width, int height, int tilex, int tiley);

void IMB_exr_set_channel(void *handle,
                         const char *layname,
                         const char *passname,
                         int xstride,
                         int ystride,
                         float *rect);
float *IMB_exr_channel_rect(void *handle,
                            const char *layname,
                            const char *passname,
                            const char *view);

void IMB_exr_read_channels(void *handle);
void IMB_exr_write_channels(void *handle);
void IMB_exrtile_write_channels(
    void *handle, int partx, int party, int level, const char *viewname, bool empty);
void IMB_exr_clear_channels(void *handle);

void IMB_exr_multilayer_convert(void *handle,
                                void *base,
                                void *(*addview)(void *base, const char *str),
                                void *(*addlayer)(void *base, const char *str),
                                void (*addpass)(void *base,
                                                void *lay,
                                                const char *str,
                                                float *rect,
                                                int totchan,
                                                const char *chan_id,
                                                const char *view));

void IMB_exr_close(void *handle);

void IMB_exr_add_view(void *handle, const char *name);

bool IMB_exr_has_multilayer(void *handle);

#ifdef __cplusplus
}  // extern "C"
#endif
