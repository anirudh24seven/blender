/** The Original Code is Copyright (C) 2005 Blender Foundation
 * All rights reserved.
 */

/** \file
 * \ingroup openexr
 */

#pragma once

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

void imb_initopenexr(void);
void imb_exitopenexr(void);

int imb_is_a_openexr(const unsigned char *mem);

int imb_save_openexr(struct ImBuf *ibuf, const char *name, int flags);

struct ImBuf *imb_load_openexr(const unsigned char *mem, size_t size, int flags, char *colorspace);

#ifdef __cplusplus
}
#endif
