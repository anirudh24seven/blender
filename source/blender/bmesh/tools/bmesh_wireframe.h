/** \file
 * \ingroup bmesh
 *
 * Wire Frame.
 */

#pragma once

void BM_mesh_wireframe(BMesh *bm,
                       const float offset,
                       const float offset_fac,
                       const float offset_fac_vg,
                       const bool use_replace,
                       const bool use_boundary,
                       const bool use_even_offset,
                       const bool use_relative_offset,
                       const bool use_crease,
                       const float crease_weight,
                       const int defgrp_index,
                       const bool defgrp_invert,
                       const short mat_offset,
                       const short mat_max,
                       const bool use_tag);
