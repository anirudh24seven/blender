#pragma once

/** \file
 * \ingroup bke
 * \brief General operations for probes.
 */

#ifdef __cplusplus
extern "C" {
#endif

struct LightProbe;
struct Main;

void BKE_lightprobe_type_set(struct LightProbe *probe, const short lightprobe_type);
void *BKE_lightprobe_add(struct Main *bmain, const char *name);
struct LightProbe *BKE_lightprobe_copy(struct Main *bmain, const struct LightProbe *probe);

#ifdef __cplusplus
}
#endif
