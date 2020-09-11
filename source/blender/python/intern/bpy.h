/** \file
 * \ingroup pythonintern
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void BPy_init_modules(void);
extern PyObject *bpy_package_py;

/* bpy_interface_atexit.c */
void BPY_atexit_register(void);
void BPY_atexit_unregister(void);

extern struct CLG_LogRef *BPY_LOG_CONTEXT;
extern struct CLG_LogRef *BPY_LOG_RNA;

#ifdef __cplusplus
}
#endif
