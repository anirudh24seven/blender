/** \file
 * \ingroup bpygpu
 */

#pragma once

#include "BLI_compiler_attrs.h"

extern PyTypeObject BPyGPUOffScreen_Type;

#define BPyGPUOffScreen_Check(v) (Py_TYPE(v) == &BPyGPUOffScreen_Type)

typedef struct BPyGPUOffScreen {
  PyObject_HEAD struct GPUOffScreen *ofs;
  bool is_saved;
} BPyGPUOffScreen;

PyObject *BPyGPUOffScreen_CreatePyObject(struct GPUOffScreen *ofs) ATTR_NONNULL(1);
