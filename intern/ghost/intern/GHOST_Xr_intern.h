/** \file
 * \ingroup GHOST
 */

#pragma once

#include <memory>
#include <vector>

#include "GHOST_Xr_openxr_includes.h"

#define CHECK_XR(call, error_msg) \
  { \
    XrResult _res = call; \
    if (XR_FAILED(_res)) { \
      throw GHOST_XrException(error_msg, _res); \
    } \
  } \
  (void)0

/**
 * Variation of CHECK_XR() that doesn't throw, but asserts for success. Especially useful for
 * destructors, which shouldn't throw.
 */
#define CHECK_XR_ASSERT(call) \
  { \
    XrResult _res = call; \
    assert(_res == XR_SUCCESS); \
    (void)_res; \
  } \
  (void)0
