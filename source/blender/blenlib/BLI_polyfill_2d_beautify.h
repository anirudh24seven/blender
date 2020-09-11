#pragma once

/** \file
 * \ingroup bli
 */

#ifdef __cplusplus
extern "C" {
#endif

struct Heap;
struct MemArena;

void BLI_polyfill_beautify(const float (*coords)[2],
                           const unsigned int coords_tot,
                           unsigned int (*tris)[3],

                           /* structs for reuse */
                           struct MemArena *arena,
                           struct Heap *eheap);

float BLI_polyfill_beautify_quad_rotate_calc_ex(const float v1[2],
                                                const float v2[2],
                                                const float v3[2],
                                                const float v4[2],
                                                const bool lock_degenerate,
                                                float *r_area);
#define BLI_polyfill_beautify_quad_rotate_calc(v1, v2, v3, v4) \
  BLI_polyfill_beautify_quad_rotate_calc_ex(v1, v2, v3, v4, false, NULL)

/* avoid realloc's when creating new structures for polyfill ngons */
#define BLI_POLYFILL_ALLOC_NGON_RESERVE 64

#ifdef __cplusplus
}
#endif
