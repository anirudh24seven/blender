#pragma once

/** \file
 * \ingroup bke
 */

#ifdef __cplusplus
extern "C" {
#endif

struct ReportList;

void BKE_mesh_calc_loop_tangent_single_ex(const struct MVert *mverts,
                                          const int numVerts,
                                          const struct MLoop *mloops,
                                          float (*r_looptangent)[4],
                                          float (*loopnors)[3],
                                          const struct MLoopUV *loopuv,
                                          const int numLoops,
                                          const struct MPoly *mpolys,
                                          const int numPolys,
                                          struct ReportList *reports);
void BKE_mesh_calc_loop_tangent_single(struct Mesh *mesh,
                                       const char *uvmap,
                                       float (*r_looptangents)[4],
                                       struct ReportList *reports);

void BKE_mesh_calc_loop_tangent_ex(const struct MVert *mvert,
                                   const struct MPoly *mpoly,
                                   const uint mpoly_len,
                                   const struct MLoop *mloop,
                                   const struct MLoopTri *looptri,
                                   const uint looptri_len,

                                   struct CustomData *loopdata,
                                   bool calc_active_tangent,
                                   const char (*tangent_names)[64],
                                   int tangent_names_len,
                                   const float (*poly_normals)[3],
                                   const float (*loop_normals)[3],
                                   const float (*vert_orco)[3],
                                   /* result */
                                   struct CustomData *loopdata_out,
                                   const uint loopdata_out_len,
                                   short *tangent_mask_curr_p);

void BKE_mesh_calc_loop_tangents(struct Mesh *me_eval,
                                 bool calc_active_tangent,
                                 const char (*tangent_names)[MAX_NAME],
                                 int tangent_names_len);

/* Helpers */
void BKE_mesh_add_loop_tangent_named_layer_for_uv(struct CustomData *uv_data,
                                                  struct CustomData *tan_data,
                                                  int numLoopData,
                                                  const char *layer_name);

#define DM_TANGENT_MASK_ORCO (1 << 9)
void BKE_mesh_calc_loop_tangent_step_0(const struct CustomData *loopData,
                                       bool calc_active_tangent,
                                       const char (*tangent_names)[64],
                                       int tangent_names_count,
                                       bool *rcalc_act,
                                       bool *rcalc_ren,
                                       int *ract_uv_n,
                                       int *rren_uv_n,
                                       char *ract_uv_name,
                                       char *rren_uv_name,
                                       short *rtangent_mask);

#ifdef __cplusplus
}
#endif
