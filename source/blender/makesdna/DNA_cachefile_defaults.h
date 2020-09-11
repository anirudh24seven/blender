/** \file
 * \ingroup DNA
 */

#pragma once

/* Struct members on own line. */
/* clang-format off */

/* -------------------------------------------------------------------- */
/** \name CacheFile Struct
 * \{ */

#define _DNA_DEFAULT_CacheFile \
  { \
    .filepath[0] = '\0', \
    .override_frame = false, \
    .frame = 0.0f, \
    .is_sequence = false, \
    .scale = 1.0f, \
    .object_paths ={NULL, NULL}, \
 \
    .handle = NULL, \
    .handle_filepath[0] = '\0', \
    .handle_readers = NULL, \
  }

/** \} */

/* clang-format on */
