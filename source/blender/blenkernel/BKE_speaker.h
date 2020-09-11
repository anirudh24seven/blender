#pragma once

/** \file
 * \ingroup bke
 * \brief General operations for speakers.
 */

#ifdef __cplusplus
extern "C" {
#endif

struct Main;
struct Speaker;

void *BKE_speaker_add(struct Main *bmain, const char *name);
struct Speaker *BKE_speaker_copy(struct Main *bmain, const struct Speaker *spk);

#ifdef __cplusplus
}
#endif
