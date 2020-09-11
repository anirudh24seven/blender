/** \file
 * \ingroup render
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* Functions */

void RE_parts_init(Render *re);
void RE_parts_free(Render *re);
void RE_parts_clamp(Render *re);

#ifdef __cplusplus
}
#endif
