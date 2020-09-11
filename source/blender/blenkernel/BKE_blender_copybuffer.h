#pragma once

/** \file
 * \ingroup bke
 */

#include "BLI_sys_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct ID;
struct Main;
struct ReportList;
struct bContext;

/* copybuffer (wrapper for BKE_blendfile_write_partial) */
void BKE_copybuffer_begin(struct Main *bmain_src);
void BKE_copybuffer_tag_ID(struct ID *id);
bool BKE_copybuffer_save(struct Main *bmain_src, const char *filename, struct ReportList *reports);
bool BKE_copybuffer_read(struct Main *bmain_dst,
                         const char *libname,
                         struct ReportList *reports,
                         const uint64_t id_types_mask);
int BKE_copybuffer_paste(struct bContext *C,
                         const char *libname,
                         const short flag,
                         struct ReportList *reports,
                         const uint64_t id_types_mask);

#ifdef __cplusplus
}
#endif
