/** \file
 * \ingroup bpygpu
 */

#pragma once

int bpygpu_ParsePrimType(PyObject *o, void *p);

PyObject *BPyInit_gpu(void);

bool bpygpu_is_init_or_error(void);
#define BPYGPU_IS_INIT_OR_ERROR_OBJ \
  if (UNLIKELY(!bpygpu_is_init_or_error())) { \
    return NULL; \
  } \
  ((void)0)
#define BPYGPU_IS_INIT_OR_ERROR_INT \
  if (UNLIKELY(!bpygpu_is_init_or_error())) { \
    return -1; \
  } \
  ((void)0)
