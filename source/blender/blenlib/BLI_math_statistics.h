/** The Original Code is Copyright (C) 2015 by Blender Foundation
 * All rights reserved.
 * */

#pragma once

/** \file
 * \ingroup bli
 */

#include "BLI_compiler_attrs.h"
#include "BLI_math_inline.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BLI_MATH_GCC_WARN_PRAGMA
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wredundant-decls"
#endif

/********************************** Covariance Matrices *********************************/

void BLI_covariance_m_vn_ex(const int n,
                            const float *cos_vn,
                            const int nbr_cos_vn,
                            const float *center,
                            const bool use_sample_correction,
                            float *r_covmat);
void BLI_covariance_m3_v3n(const float (*cos_v3)[3],
                           const int nbr_cos_v3,
                           const bool use_sample_correction,
                           float r_covmat[3][3],
                           float r_center[3]);

#ifdef BLI_MATH_GCC_WARN_PRAGMA
#  pragma GCC diagnostic pop
#endif

#ifdef __cplusplus
}
#endif
