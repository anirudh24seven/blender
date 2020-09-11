/** \file
 * \ingroup freestyle
 */

#pragma once

extern "C" {
#include <Python.h>
}

#include "../system/FreestyleConfig.h"

using namespace std;

#include "../stroke/StrokeShader.h"

using namespace Freestyle;

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////////////////

extern PyTypeObject StrokeShader_Type;

#define BPy_StrokeShader_Check(v) \
  (PyObject_IsInstance((PyObject *)v, (PyObject *)&StrokeShader_Type))

/*---------------------------Python BPy_StrokeShader structure definition----------*/
typedef struct {
  PyObject_HEAD StrokeShader *ss;
} BPy_StrokeShader;

/*---------------------------Python BPy_StrokeShader visible prototypes-----------*/

int StrokeShader_Init(PyObject *module);

///////////////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
