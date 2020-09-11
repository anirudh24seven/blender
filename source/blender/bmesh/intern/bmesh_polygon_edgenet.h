#pragma once

/** \file
 * \ingroup bmesh
 */

bool BM_face_split_edgenet(BMesh *bm,
                           BMFace *f,
                           BMEdge **edge_net,
                           const int edge_net_len,
                           BMFace ***r_face_arr,
                           int *r_face_arr_len);

bool BM_face_split_edgenet_connect_islands(BMesh *bm,
                                           BMFace *f,
                                           BMEdge **edge_net_init,
                                           const uint edge_net_init_len,
                                           bool use_partial_connect,
                                           struct MemArena *arena,
                                           BMEdge ***r_edge_net_new,
                                           uint *r_edge_net_new_len) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL(1, 2, 3, 6, 7, 8);
