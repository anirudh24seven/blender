#pragma once

/** \file
 * \ingroup bmesh
 */

void BM_mesh_bisect_plane(BMesh *bm,
                          const float plane[4],
                          const bool use_snap_center,
                          const bool use_tag,
                          const short oflag_center,
                          const short oflag_new,
                          const float eps);
