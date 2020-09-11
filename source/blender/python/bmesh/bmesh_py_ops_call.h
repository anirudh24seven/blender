/** \file
 * \ingroup pybmesh
 */

#pragma once

typedef struct {
  PyObject_HEAD /* required python macro   */
      const char *opname;
} BPy_BMeshOpFunc;

PyObject *BPy_BMO_call(BPy_BMeshOpFunc *self, PyObject *args, PyObject *kw);
