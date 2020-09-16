#pragma once

/** \file
 * \ingroup bmesh
 */

#ifdef __cplusplus
extern "C" {
#endif

bool BM_mesh_boolean(BMesh *bm,
                     struct BMLoop *(*looptris)[3],
                     const int looptris_tot,
                     int (*test_fn)(BMFace *f, void *user_data),
                     void *user_data,
                     const int nshapes,
                     const bool use_self,
                     const int boolean_mode);

bool BM_mesh_boolean_knife(BMesh *bm,
                           struct BMLoop *(*looptris)[3],
                           const int looptris_tot,
                           int (*test_fn)(BMFace *f, void *user_data),
                           void *user_data,
                           const int nshapes,
                           const bool use_self,
                           const bool use_separate_all);

#ifdef __cplusplus
}
#endif
