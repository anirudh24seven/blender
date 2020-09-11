/** \file
 * \ingroup pygen
 *
 * This file contains wrapper functions related to global interpreter lock.
 * these functions are slightly different from the original Python API,
 * don't throw SIGABRT even if the thread state is NULL. */

#include <Python.h>

#include "../BPY_extern.h"
#include "BLI_utildefines.h"

/* analogue of PyEval_SaveThread() */
BPy_ThreadStatePtr BPY_thread_save(void)
{
  PyThreadState *tstate = PyThreadState_Swap(NULL);
  /* note: tstate can be NULL when quitting Blender */

  if (tstate && PyEval_ThreadsInitialized()) {
    PyEval_ReleaseLock();
  }

  return (BPy_ThreadStatePtr)tstate;
}

/* analogue of PyEval_RestoreThread() */
void BPY_thread_restore(BPy_ThreadStatePtr tstate)
{
  if (tstate) {
    PyEval_RestoreThread((PyThreadState *)tstate);
  }
}
