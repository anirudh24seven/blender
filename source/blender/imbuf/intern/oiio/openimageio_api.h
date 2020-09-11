/** \file
 * \ingroup openimageio
 */

#pragma once

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

struct ImBuf;

int imb_is_a_photoshop(const char *name);

int imb_save_photoshop(struct ImBuf *ibuf, const char *name, int flags);

struct ImBuf *imb_load_photoshop(const char *name, int flags, char *colorspace);

int OIIO_getVersionHex(void);

#ifdef __cplusplus
}

#endif
