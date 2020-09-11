/** The Original Code is Copyright (C) 2004 Blender Foundation.
 * All rights reserved.
 */

#pragma once

/** \file
 * \ingroup bmesh
 *
 * Private function prototypes for bmesh public API.
 * This file is a grab-bag of functions from various
 * parts of the bmesh internals.
 */

/* returns positive nonzero on error */

#ifdef NDEBUG
/* No error checking for release,
 * it can take most of the CPU time when running some tools. */
#  define BM_CHECK_ELEMENT(el) (void)(el)
#else
int bmesh_elem_check(void *element, const char htype);
#  define BM_CHECK_ELEMENT(el) \
    { \
      if (bmesh_elem_check(el, ((BMHeader *)el)->htype)) { \
        printf( \
            "check_element failure, with code %i on line %i in file\n" \
            "    \"%s\"\n\n", \
            bmesh_elem_check(el, ((BMHeader *)el)->htype), \
            __LINE__, \
            __FILE__); \
      } \
    } \
    ((void)0)
#endif

int bmesh_radial_length(const BMLoop *l);
int bmesh_disk_count_at_most(const BMVert *v, const int count_max);
int bmesh_disk_count(const BMVert *v);

/**
 * Internal BMHeader.api_flag
 * \note Ensure different parts of the API do not conflict
 * on using these internal flags!*/
enum {
  _FLAG_JF = (1 << 0),       /* join faces */
  _FLAG_MF = (1 << 1),       /* make face */
  _FLAG_MV = (1 << 1),       /* make face, vertex */
  _FLAG_OVERLAP = (1 << 2),  /* general overlap flag  */
  _FLAG_WALK = (1 << 3),     /* general walk flag (keep clean) */
  _FLAG_WALK_ALT = (1 << 4), /* same as _FLAG_WALK, for when a second tag is needed */

  _FLAG_ELEM_CHECK = (1 << 7), /* reserved for bmesh_elem_check */
};

#define BM_ELEM_API_FLAG_ENABLE(element, f) \
  { \
    ((element)->head.api_flag |= (f)); \
  } \
  (void)0
#define BM_ELEM_API_FLAG_DISABLE(element, f) \
  { \
    ((element)->head.api_flag &= (uchar) ~(f)); \
  } \
  (void)0
#define BM_ELEM_API_FLAG_TEST(element, f) ((element)->head.api_flag & (f))
#define BM_ELEM_API_FLAG_CLEAR(element) \
  { \
    ((element)->head.api_flag = 0); \
  } \
  (void)0

void poly_rotate_plane(const float normal[3], float (*verts)[3], const uint nverts);

/* include the rest of our private declarations */
#include "bmesh_structure.h"
