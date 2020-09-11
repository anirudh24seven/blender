#pragma once

/** \file
 * \ingroup bli
 */

#ifdef __cplusplus
extern "C" {
#endif

struct MemArena;

void BLI_polyfill_calc_arena(const float (*coords)[2],
                             const unsigned int coords_tot,
                             const int coords_sign,
                             unsigned int (*r_tris)[3],

                             struct MemArena *arena);

void BLI_polyfill_calc(const float (*coords)[2],
                       const unsigned int coords_tot,
                       const int coords_sign,
                       unsigned int (*r_tris)[3]);

/* default size of polyfill arena */
#define BLI_POLYFILL_ARENA_SIZE MEM_SIZE_OPTIMAL(1 << 14)

#ifdef __cplusplus
}
#endif
