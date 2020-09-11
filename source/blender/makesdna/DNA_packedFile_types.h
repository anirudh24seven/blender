/** \file
 * \ingroup DNA
 */

#pragma once

typedef struct PackedFile {
  int size;
  int seek;
  void *data;
} PackedFile;
