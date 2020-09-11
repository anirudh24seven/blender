/** \file
 * \ingroup pymathutils
 */

#pragma once

extern PyTypeObject vector_Type;

#define VectorObject_Check(v) PyObject_TypeCheck((v), &vector_Type)
#define VectorObject_CheckExact(v) (Py_TYPE(v) == &vector_Type)

typedef struct {
  BASE_MATH_MEMBERS(vec);

  int size; /* vec size 2 or more */
} VectorObject;

/*prototypes*/
PyObject *Vector_CreatePyObject(const float *vec,
                                const int size,
                                PyTypeObject *base_type) ATTR_WARN_UNUSED_RESULT;
PyObject *Vector_CreatePyObject_wrap(float *vec,
                                     const int size,
                                     PyTypeObject *base_type) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL(1);
PyObject *Vector_CreatePyObject_cb(PyObject *user,
                                   int size,
                                   unsigned char cb_type,
                                   unsigned char subtype) ATTR_WARN_UNUSED_RESULT;
PyObject *Vector_CreatePyObject_alloc(float *vec,
                                      const int size,
                                      PyTypeObject *base_type) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL(1);
