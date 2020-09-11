/** \file
 * \ingroup imbdds
 */

#pragma once

#include "../../IMB_imbuf.h"

#ifdef __cplusplus
extern "C" {
#endif

int imb_is_a_dds(const unsigned char *mem); /* use only first 32 bytes of mem */
int imb_save_dds(struct ImBuf *ibuf, const char *name, int flags);
struct ImBuf *imb_load_dds(const unsigned char *mem,
                           size_t size,
                           int flags,
                           char colorspace[IM_MAX_SPACE]);

#ifdef __cplusplus
}
#endif
