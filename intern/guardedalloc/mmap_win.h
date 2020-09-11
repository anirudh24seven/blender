/** \file
 * \ingroup MEM
 */

#ifndef __MMAP_WIN_H__
#define __MMAP_WIN_H__

#define PROT_NONE 0
#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_EXEC 4

#define MAP_FILE 0
#define MAP_SHARED 1
#define MAP_PRIVATE 2
#define MAP_TYPE 0xF
#define MAP_FIXED 0x10
#define MAP_ANONYMOUS 0x20
#define MAP_ANON MAP_ANONYMOUS

#define MAP_FAILED ((void *)-1)

/* needed for uintptr_t, exception, dont use BLI anywhere else in MEM_* */
#include "../../source/blender/blenlib/BLI_sys_types.h"

#include <sys/types.h>

void *mmap(void *start, size_t len, int prot, int flags, int fd, off_t offset);
intptr_t munmap(void *ptr, size_t size);

#endif
