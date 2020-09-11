/** \file
 * \ingroup bpygpu
 */

#pragma once

extern PyTypeObject BPyGPUShader_Type;

#define BPyGPUShader_Check(v) (Py_TYPE(v) == &BPyGPUShader_Type)

typedef struct BPyGPUShader {
  PyObject_VAR_HEAD struct GPUShader *shader;
  bool is_builtin;
} BPyGPUShader;

PyObject *BPyGPUShader_CreatePyObject(struct GPUShader *shader, bool is_builtin);
PyObject *BPyInit_gpu_shader(void);
