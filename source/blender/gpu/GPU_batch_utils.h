/** \file
 * \ingroup gpu
 */

#pragma once

#include "BLI_compiler_attrs.h"
#include "BLI_sys_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct rctf;

/* gpu_batch_utils.c */
struct GPUBatch *GPU_batch_tris_from_poly_2d_encoded(
    const uchar *polys_flat, uint polys_flat_len, const struct rctf *rect) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL(1);
struct GPUBatch *GPU_batch_wire_from_poly_2d_encoded(
    const uchar *polys_flat, uint polys_flat_len, const struct rctf *rect) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL(1);

/* Only use by draw manager. Use the presets function instead for interface. */
struct GPUBatch *gpu_batch_sphere(int lat_res, int lon_res) ATTR_WARN_UNUSED_RESULT;

#ifdef __cplusplus
}
#endif
