/** The Original Code is Copyright (C) 2004 Blender Foundation.
 * All rights reserved.
 * external writefile function prototypes
 */

#pragma once

/** \file
 * \ingroup blenloader
 */

struct Scene;
struct GHash;

typedef struct {
  void *next, *prev;
  const char *buf;
  /** Size in bytes. */
  unsigned int size;
  /** When true, this chunk doesn't own the memory, it's shared with a previous #MemFileChunk */
  bool is_identical;
  /** When true, this chunk is also identical to the one in the next step (used by undo code to
   * detect unchanged IDs).
   * Defined when writing the next step (i.e. last undo step has those always false). */
  bool is_identical_future;
  /** Session UUID of the ID being currently written (MAIN_ID_SESSION_UUID_UNSET when not writing
   * ID-related data). Used to find matching chunks in previous memundo step. */
  uint id_session_uuid;
} MemFileChunk;

typedef struct MemFile {
  ListBase chunks;
  size_t size;
} MemFile;

typedef struct MemFileWriteData {
  MemFile *written_memfile;
  MemFile *reference_memfile;

  uint current_id_session_uuid;
  MemFileChunk *reference_current_chunk;

  /** Maps an ID session uuid to its first reference MemFileChunk, if existing. */
  struct GHash *id_session_uuid_mapping;
} MemFileWriteData;

typedef struct MemFileUndoData {
  char filename[1024]; /* FILE_MAX */
  MemFile memfile;
  size_t undo_size;
} MemFileUndoData;

/* actually only used writefile.c */

void BLO_memfile_write_init(MemFileWriteData *mem_data,
                            MemFile *written_memfile,
                            MemFile *reference_memfile);
void BLO_memfile_write_finalize(MemFileWriteData *mem_data);

void BLO_memfile_chunk_add(MemFileWriteData *mem_data, const char *buf, unsigned int size);

/* exports */
extern void BLO_memfile_free(MemFile *memfile);
extern void BLO_memfile_merge(MemFile *first, MemFile *second);
extern void BLO_memfile_clear_future(MemFile *memfile);

/* utilities */
extern struct Main *BLO_memfile_main_get(struct MemFile *memfile,
                                         struct Main *bmain,
                                         struct Scene **r_scene);
extern bool BLO_memfile_write_file(struct MemFile *memfile, const char *filename);
