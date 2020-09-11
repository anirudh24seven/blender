#pragma once

/** \file
 * \ingroup BLI
 */

#include "BLI_compiler_attrs.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t BLI_timecode_string_from_time(char *str,
                                     const size_t maxncpy,
                                     const int brevity_level,
                                     const float time_seconds,
                                     const double scene_fps,
                                     const short timecode_style) ATTR_NONNULL();

size_t BLI_timecode_string_from_time_simple(char *str,
                                            const size_t maxncpy,
                                            const double time_seconds) ATTR_NONNULL();

size_t BLI_timecode_string_from_time_seconds(char *str,
                                             const size_t maxncpy,
                                             const int brevity_level,
                                             const float time_seconds) ATTR_NONNULL();

#ifdef __cplusplus
}
#endif
