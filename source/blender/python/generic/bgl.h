/** \file
 * \ingroup pygen
 */

#pragma once

PyObject *BPyInit_bgl(void);

struct _Buffer *BGL_MakeBuffer(int type, int ndimensions, int *dimensions, void *initbuffer);

int BGL_typeSize(int type);

/**
 * Buffer Object
 *
 * For Python access to OpenGL functions requiring a pointer.
 */
typedef struct _Buffer {
  PyObject_VAR_HEAD PyObject *parent;

  int type; /* GL_BYTE, GL_SHORT, GL_INT, GL_FLOAT */
  int ndimensions;
  int *dimensions;

  union {
    char *asbyte;
    short *asshort;
    int *asint;
    float *asfloat;
    double *asdouble;

    void *asvoid;
  } buf;
} Buffer;

/** The type object */
extern PyTypeObject BGL_bufferType;
