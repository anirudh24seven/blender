/** \file
 * \ingroup MEM
 */

#ifdef WIN32

#  include <errno.h>
#  include <io.h>
#  include <stdio.h>
#  include <sys/types.h>
#  include <windows.h>

#  include "mmap_win.h"

#  ifndef FILE_MAP_EXECUTE
// not defined in earlier versions of the Platform  SDK (before February 2003)
#    define FILE_MAP_EXECUTE 0x0020
#  endif

/* copied from BLI_utildefines.h, ugh */
#  ifdef __GNUC__
#    define UNUSED(x) UNUSED_##x __attribute__((__unused__))
#  else
#    define UNUSED(x) x
#  endif

/* --------------------------------------------------------------------- */
/* local storage definitions                                             */
/* --------------------------------------------------------------------- */
/* all memory mapped chunks are put in linked lists */
typedef struct mmapLink {
  struct mmapLink *next, *prev;
} mmapLink;

typedef struct mmapListBase {
  void *first, *last;
} mmapListBase;

typedef struct MemMap {
  struct MemMap *next, *prev;
  void *mmap;
  HANDLE fhandle;
  HANDLE maphandle;
} MemMap;

/* --------------------------------------------------------------------- */
/* local functions                                                       */
/* --------------------------------------------------------------------- */

static void mmap_addtail(volatile mmapListBase *listbase, void *vlink);
static void mmap_remlink(volatile mmapListBase *listbase, void *vlink);
static void *mmap_findlink(volatile mmapListBase *listbase, void *ptr);

static int mmap_get_prot_flags(int flags);
static int mmap_get_access_flags(int flags);

/* --------------------------------------------------------------------- */
/* vars                                                                  */
/* --------------------------------------------------------------------- */
volatile static struct mmapListBase _mmapbase;
volatile static struct mmapListBase *mmapbase = &_mmapbase;

/* --------------------------------------------------------------------- */
/* implementation                                                        */
/* --------------------------------------------------------------------- */

/* mmap for windows */
void *mmap(void *UNUSED(start), size_t len, int prot, int flags, int fd, off_t offset)
{
  HANDLE fhandle = INVALID_HANDLE_VALUE;
  HANDLE maphandle;
  int prot_flags = mmap_get_prot_flags(prot);
  int access_flags = mmap_get_access_flags(prot);
  MemMap *mm = NULL;
  void *ptr = NULL;

  if (flags & MAP_FIXED) {
    return MAP_FAILED;
  }

#  if 0
  if (fd == -1) {
    _set_errno(EBADF);
    return MAP_FAILED;
  }
#  endif

  if (fd != -1) {
    fhandle = (HANDLE)_get_osfhandle(fd);
  }
  if (fhandle == INVALID_HANDLE_VALUE) {
    if (!(flags & MAP_ANONYMOUS)) {
      errno = EBADF;
      return MAP_FAILED;
    }
  }
  else {
    if (!DuplicateHandle(GetCurrentProcess(),
                         fhandle,
                         GetCurrentProcess(),
                         &fhandle,
                         0,
                         FALSE,
                         DUPLICATE_SAME_ACCESS)) {
      return MAP_FAILED;
    }
  }

  /* Split 64 bit size into low and high bits. */
  DWORD len_bits_high = len >> 32;
  DWORD len_bits_low = len & 0xFFFFFFFF;

  maphandle = CreateFileMapping(fhandle, NULL, prot_flags, len_bits_high, len_bits_low, NULL);
  if (maphandle == 0) {
    errno = EBADF;
    return MAP_FAILED;
  }

  ptr = MapViewOfFile(maphandle, access_flags, 0, offset, 0);
  if (ptr == NULL) {
    DWORD dwLastErr = GetLastError();
    if (dwLastErr == ERROR_MAPPED_ALIGNMENT) {
      errno = EINVAL;
    }
    else {
      errno = EACCES;
    }
    CloseHandle(maphandle);
    return MAP_FAILED;
  }

  mm = (MemMap *)malloc(sizeof(MemMap));
  if (!mm) {
    errno = ENOMEM;
  }
  mm->fhandle = fhandle;
  mm->maphandle = maphandle;
  mm->mmap = ptr;
  mmap_addtail(mmapbase, mm);

  return ptr;
}

/* munmap for windows */
intptr_t munmap(void *ptr, size_t UNUSED(size))
{
  MemMap *mm = mmap_findlink(mmapbase, ptr);
  if (!mm) {
    errno = EINVAL;
    return -1;
  }
  UnmapViewOfFile(mm->mmap);
  CloseHandle(mm->maphandle);
  CloseHandle(mm->fhandle);
  mmap_remlink(mmapbase, mm);
  free(mm);
  return 0;
}

/* --------------------------------------------------------------------- */
/* local functions                                                       */
/* --------------------------------------------------------------------- */

static void mmap_addtail(volatile mmapListBase *listbase, void *vlink)
{
  struct mmapLink *link = vlink;

  if (link == NULL) {
    return;
  }
  if (listbase == NULL) {
    return;
  }

  link->next = 0;
  link->prev = listbase->last;

  if (listbase->last) {
    ((struct mmapLink *)listbase->last)->next = link;
  }
  if (listbase->first == NULL) {
    listbase->first = link;
  }
  listbase->last = link;
}

static void mmap_remlink(volatile mmapListBase *listbase, void *vlink)
{
  struct mmapLink *link = vlink;

  if (link == NULL) {
    return;
  }
  if (listbase == NULL) {
    return;
  }
  if (link->next) {
    link->next->prev = link->prev;
  }
  if (link->prev) {
    link->prev->next = link->next;
  }

  if (listbase->last == link) {
    listbase->last = link->prev;
  }
  if (listbase->first == link) {
    listbase->first = link->next;
  }
}

static void *mmap_findlink(volatile mmapListBase *listbase, void *ptr)
{
  MemMap *mm;

  if (ptr == NULL) {
    return NULL;
  }
  if (listbase == NULL) {
    return NULL;
  }

  mm = (MemMap *)listbase->first;
  while (mm) {
    if (mm->mmap == ptr) {
      return mm;
    }
    mm = mm->next;
  }
  return NULL;
}

static int mmap_get_prot_flags(int flags)
{
  int prot = PAGE_NOACCESS;

  if ((flags & PROT_READ) == PROT_READ) {
    if ((flags & PROT_WRITE) == PROT_WRITE) {
      prot = (flags & PROT_EXEC) ? PAGE_EXECUTE_READWRITE : PAGE_READWRITE;
    }
    else {
      prot = (flags & PROT_EXEC) ? PAGE_EXECUTE_READ : PAGE_READONLY;
    }
  }
  else if ((flags & PROT_WRITE) == PROT_WRITE) {
    prot = (flags & PROT_EXEC) ? PAGE_EXECUTE_READ : PAGE_WRITECOPY;
  }
  else if ((flags & PROT_EXEC) == PROT_EXEC) {
    prot = PAGE_EXECUTE_READ;
  }
  return prot;
}

static int mmap_get_access_flags(int flags)
{
  int access = 0;

  if ((flags & PROT_READ) == PROT_READ) {
    if ((flags & PROT_WRITE) == PROT_WRITE) {
      access = FILE_MAP_WRITE;
    }
    else {
      access = (flags & PROT_EXEC) ? FILE_MAP_EXECUTE : FILE_MAP_READ;
    }
  }
  else if ((flags & PROT_WRITE) == PROT_WRITE) {
    access = FILE_MAP_COPY;
  }
  else if ((flags & PROT_EXEC) == PROT_EXEC) {
    access = FILE_MAP_EXECUTE;
  }
  return access;
}

#endif  // WIN32
