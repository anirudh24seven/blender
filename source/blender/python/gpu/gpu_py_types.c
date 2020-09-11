/** \file
 * \ingroup bpygpu
 *
 * - Use ``bpygpu_`` for local API.
 * - Use ``BPyGPU`` for public API.
 */

#include <Python.h>

#include "../generic/py_capi_utils.h"
#include "../generic/python_utildefines.h"

#include "gpu_py_types.h" /* own include */

/* -------------------------------------------------------------------- */
/** \name GPU Types Module
 * \{ */

static struct PyModuleDef BPyGPU_types_module_def = {
    PyModuleDef_HEAD_INIT,
    .m_name = "gpu.types",
};

PyObject *BPyInit_gpu_types(void)
{
  PyObject *submodule;

  submodule = PyModule_Create(&BPyGPU_types_module_def);

  if (PyType_Ready(&BPyGPUVertFormat_Type) < 0) {
    return NULL;
  }
  if (PyType_Ready(&BPyGPUVertBuf_Type) < 0) {
    return NULL;
  }
  if (PyType_Ready(&BPyGPUIndexBuf_Type) < 0) {
    return NULL;
  }
  if (PyType_Ready(&BPyGPUBatch_Type) < 0) {
    return NULL;
  }
  if (PyType_Ready(&BPyGPUOffScreen_Type) < 0) {
    return NULL;
  }
  if (PyType_Ready(&BPyGPUShader_Type) < 0) {
    return NULL;
  }

#define MODULE_TYPE_ADD(s, t) \
  PyModule_AddObject(s, t.tp_name, (PyObject *)&t); \
  Py_INCREF((PyObject *)&t)

  MODULE_TYPE_ADD(submodule, BPyGPUVertFormat_Type);
  MODULE_TYPE_ADD(submodule, BPyGPUVertBuf_Type);
  MODULE_TYPE_ADD(submodule, BPyGPUIndexBuf_Type);
  MODULE_TYPE_ADD(submodule, BPyGPUBatch_Type);
  MODULE_TYPE_ADD(submodule, BPyGPUOffScreen_Type);
  MODULE_TYPE_ADD(submodule, BPyGPUShader_Type);

#undef MODULE_TYPE_ADD

  return submodule;
}

/** \} */
