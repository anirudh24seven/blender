/** \file
 * \ingroup modifiers
 */

#pragma once

/* MOD_meshcache_mdd.c */
bool MOD_meshcache_read_mdd_index(FILE *fp,
                                  float (*vertexCos)[3],
                                  const int vertex_tot,
                                  const int index,
                                  const float factor,
                                  const char **err_str);
bool MOD_meshcache_read_mdd_frame(FILE *fp,
                                  float (*vertexCos)[3],
                                  const int verts_tot,
                                  const char interp,
                                  const float frame,
                                  const char **err_str);
bool MOD_meshcache_read_mdd_times(const char *filepath,
                                  float (*vertexCos)[3],
                                  const int verts_tot,
                                  const char interp,
                                  const float time,
                                  const float fps,
                                  const char time_mode,
                                  const char **err_str);

/* MOD_meshcache_pc2.c */
bool MOD_meshcache_read_pc2_index(FILE *fp,
                                  float (*vertexCos)[3],
                                  const int verts_tot,
                                  const int index,
                                  const float factor,
                                  const char **err_str);
bool MOD_meshcache_read_pc2_frame(FILE *fp,
                                  float (*vertexCos)[3],
                                  const int verts_tot,
                                  const char interp,
                                  const float frame,
                                  const char **err_str);
bool MOD_meshcache_read_pc2_times(const char *filepath,
                                  float (*vertexCos)[3],
                                  const int verts_tot,
                                  const char interp,
                                  const float time,
                                  const float fps,
                                  const char time_mode,
                                  const char **err_str);

/* MOD_meshcache_util.c */
void MOD_meshcache_calc_range(const float frame,
                              const char interp,
                              const int frame_tot,
                              int r_index_range[2],
                              float *r_factor);

#define FRAME_SNAP_EPS 0.0001f
