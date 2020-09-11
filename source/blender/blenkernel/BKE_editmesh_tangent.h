#pragma once

/** \file
 * \ingroup bke
 */

#ifdef __cplusplus
extern "C" {
#endif

void BKE_editmesh_loop_tangent_calc(BMEditMesh *em,
                                    bool calc_active_tangent,
                                    const char (*tangent_names)[MAX_NAME],
                                    int tangent_names_len,
                                    const float (*poly_normals)[3],
                                    const float (*loop_normals)[3],
                                    const float (*vert_orco)[3],
                                    CustomData *dm_loopdata_out,
                                    const uint dm_loopdata_out_len,
                                    short *tangent_mask_curr_p);

#ifdef __cplusplus
}
#endif
