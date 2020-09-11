/** \file
 * \ingroup pythonintern
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

PyObject *BPY_rna_props(void);

PyObject *BPy_PointerProperty(PyObject *self, PyObject *args, PyObject *kw);
PyObject *BPy_CollectionProperty(PyObject *self, PyObject *args, PyObject *kw);
StructRNA *pointer_type_from_py(PyObject *value, const char *error_prefix);

#define PYRNA_STACK_ARRAY RNA_STACK_ARRAY

#ifdef __cplusplus
}
#endif
