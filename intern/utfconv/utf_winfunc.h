/** The Original Code is Copyright (C) 2012 Blender Foundation.
 * All rights reserved.
 *
 */

#ifndef __UTF_WINFUNC_H__
#define __UTF_WINFUNC_H__

#ifndef WIN32
#  error "This file can only compile on windows"
#endif

#include <stdio.h>

FILE *ufopen(const char *filename, const char *mode);
int uopen(const char *filename, int oflag, int pmode);
int uaccess(const char *filename, int mode);
int urename(const char *oldname, const char *newname);

char *u_alloc_getenv(const char *varname);
void u_free_getenv(char *val);

int uput_getenv(const char *varname, char *value, size_t buffsize);
int uputenv(const char *name, const char *value);

int umkdir(const char *pathname);

#endif /* __UTF_WINFUNC_H__ */
