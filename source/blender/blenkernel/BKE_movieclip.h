#pragma once

/** \file
 * \ingroup bke
 */

#ifdef __cplusplus
extern "C" {
#endif

struct Depsgraph;
struct ImBuf;
struct Main;
struct MovieClip;
struct MovieClipScopes;
struct MovieClipUser;
struct MovieDistortion;

struct MovieClip *BKE_movieclip_copy(struct Main *bmain, const struct MovieClip *clip);

struct MovieClip *BKE_movieclip_file_add(struct Main *bmain, const char *name);
struct MovieClip *BKE_movieclip_file_add_exists_ex(struct Main *bmain,
                                                   const char *filepath,
                                                   bool *r_exists);
struct MovieClip *BKE_movieclip_file_add_exists(struct Main *bmain, const char *filepath);
void BKE_movieclip_reload(struct Main *bmain, struct MovieClip *clip);
void BKE_movieclip_clear_cache(struct MovieClip *clip);
void BKE_movieclip_clear_proxy_cache(struct MovieClip *clip);

void BKE_movieclip_convert_multilayer_ibuf(struct ImBuf *ibuf);

struct ImBuf *BKE_movieclip_get_ibuf(struct MovieClip *clip, struct MovieClipUser *user);
struct ImBuf *BKE_movieclip_get_postprocessed_ibuf(struct MovieClip *clip,
                                                   struct MovieClipUser *user,
                                                   int postprocess_flag);
struct ImBuf *BKE_movieclip_get_stable_ibuf(struct MovieClip *clip,
                                            struct MovieClipUser *user,
                                            float loc[2],
                                            float *scale,
                                            float *angle,
                                            int postprocess_flag);
struct ImBuf *BKE_movieclip_get_ibuf_flag(struct MovieClip *clip,
                                          struct MovieClipUser *user,
                                          int flag,
                                          int cache_flag);
void BKE_movieclip_get_size(struct MovieClip *clip,
                            struct MovieClipUser *user,
                            int *width,
                            int *height);
void BKE_movieclip_get_size_fl(struct MovieClip *clip, struct MovieClipUser *user, float size[2]);
int BKE_movieclip_get_duration(struct MovieClip *clip);
float BKE_movieclip_get_fps(struct MovieClip *clip);
void BKE_movieclip_get_aspect(struct MovieClip *clip, float *aspx, float *aspy);
bool BKE_movieclip_has_frame(struct MovieClip *clip, struct MovieClipUser *user);
void BKE_movieclip_user_set_frame(struct MovieClipUser *user, int framenr);

void BKE_movieclip_update_scopes(struct MovieClip *clip,
                                 struct MovieClipUser *user,
                                 struct MovieClipScopes *scopes);

void BKE_movieclip_get_cache_segments(struct MovieClip *clip,
                                      struct MovieClipUser *user,
                                      int *r_totseg,
                                      int **r_points);

void BKE_movieclip_build_proxy_frame(struct MovieClip *clip,
                                     int clip_flag,
                                     struct MovieDistortion *distortion,
                                     int cfra,
                                     int *build_sizes,
                                     int build_count,
                                     bool undistorted);

void BKE_movieclip_build_proxy_frame_for_ibuf(struct MovieClip *clip,
                                              struct ImBuf *ibuf,
                                              struct MovieDistortion *distortion,
                                              int cfra,
                                              int *build_sizes,
                                              int build_count,
                                              bool undistorted);

float BKE_movieclip_remap_scene_to_clip_frame(const struct MovieClip *clip, float framenr);
float BKE_movieclip_remap_clip_to_scene_frame(const struct MovieClip *clip, float framenr);

void BKE_movieclip_filename_for_frame(struct MovieClip *clip,
                                      struct MovieClipUser *user,
                                      char *name);
struct ImBuf *BKE_movieclip_anim_ibuf_for_frame(struct MovieClip *clip,
                                                struct MovieClipUser *user);

bool BKE_movieclip_has_cached_frame(struct MovieClip *clip, struct MovieClipUser *user);
bool BKE_movieclip_put_frame_if_possible(struct MovieClip *clip,
                                         struct MovieClipUser *user,
                                         struct ImBuf *ibuf);

struct GPUTexture *BKE_movieclip_get_gpu_texture(struct MovieClip *clip,
                                                 struct MovieClipUser *cuser);

void BKE_movieclip_free_gputexture(struct MovieClip *clip);

/* Dependency graph evaluation. */

void BKE_movieclip_eval_update(struct Depsgraph *depsgraph,
                               struct Main *bmain,
                               struct MovieClip *clip);
void BKE_movieclip_eval_selection_update(struct Depsgraph *depsgraph, struct MovieClip *clip);

/* caching flags */
#define MOVIECLIP_CACHE_SKIP (1 << 0)

/* postprocessing flags */
#define MOVIECLIP_DISABLE_RED (1 << 0)
#define MOVIECLIP_DISABLE_GREEN (1 << 1)
#define MOVIECLIP_DISABLE_BLUE (1 << 2)
#define MOVIECLIP_PREVIEW_GRAYSCALE (1 << 3)

#ifdef __cplusplus
}
#endif
