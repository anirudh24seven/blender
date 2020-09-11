/** \file
 * \ingroup pythonintern
 */

#pragma once

struct wmOperatorType;

#ifdef __cplusplus
extern "C" {
#endif

/* these are used for operator methods, used by bpy_operator.c */
PyObject *PYOP_wrap_macro_define(PyObject *self, PyObject *args);

/* exposed to rna/wm api */
void BPY_RNA_operator_wrapper(struct wmOperatorType *ot, void *userdata);
void BPY_RNA_operator_macro_wrapper(struct wmOperatorType *ot, void *userdata);

#ifdef __cplusplus
}
#endif
