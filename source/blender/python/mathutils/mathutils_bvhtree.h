/** \file
 * \ingroup mathutils
 */

#pragma once

PyMODINIT_FUNC PyInit_mathutils_bvhtree(void);

extern PyTypeObject PyBVHTree_Type;

#define PyBVHTree_Check(v) PyObject_TypeCheck((v), &PyBVHTree_Type)
#define PyBVHTree_CheckExact(v) (Py_TYPE(v) == &PyBVHTree_Type)
