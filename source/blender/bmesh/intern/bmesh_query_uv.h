#pragma once

/** \file
 * \ingroup bmesh
 */

float BM_loop_uv_calc_edge_length_squared(const BMLoop *l,
                                          const int cd_loop_uv_offset) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL();
float BM_loop_uv_calc_edge_length(const BMLoop *l,
                                  const int cd_loop_uv_offset) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL();

void BM_face_uv_calc_center_median_weighted(const BMFace *f,
                                            const float aspect[2],
                                            const int cd_loop_uv_offset,
                                            float r_cent[2]) ATTR_NONNULL();
void BM_face_uv_calc_center_median(const BMFace *f, const int cd_loop_uv_offset, float r_cent[2])
    ATTR_NONNULL();

float BM_face_uv_calc_cross(const BMFace *f, const int cd_loop_uv_offset) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL();

bool BM_loop_uv_share_edge_check_with_limit(BMLoop *l_a,
                                            BMLoop *l_b,
                                            const float limit[2],
                                            const int cd_loop_uv_offset) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL();

bool BM_loop_uv_share_edge_check(BMLoop *l_a,
                                 BMLoop *l_b,
                                 const int cd_loop_uv_offset) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL();

bool BM_edge_uv_share_vert_check(BMEdge *e, BMLoop *l_a, BMLoop *l_b, const int cd_loop_uv_offset)
    ATTR_WARN_UNUSED_RESULT ATTR_NONNULL();

bool BM_loop_uv_share_vert_check(BMLoop *l_a,
                                 BMLoop *l_b,
                                 const int cd_loop_uv_offset) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL();
