/** \file
 * \ingroup python
 *
 * Functionality relating to Python setup & tear down.
 */

#pragma once

struct bContext;

#ifdef __cplusplus
extern "C" {
#endif

/* For 'FILE'. */
#include <stdio.h>

/* bpy_interface.c */
void BPY_python_start(int argc, const char **argv);
void BPY_python_end(void);
void BPY_python_reset(struct bContext *C);
void BPY_python_use_system_env(void);
void BPY_python_backtrace(FILE *fp);

#ifdef __cplusplus
} /* extern "C" */
#endif
