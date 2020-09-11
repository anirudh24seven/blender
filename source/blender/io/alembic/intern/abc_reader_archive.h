/** The Original Code is Copyright (C) 2016 Kévin Dietrich.
 * All rights reserved.
 */
#pragma once

/** \file
 * \ingroup balembic
 */

#include <Alembic/Abc/All.h>
#include <Alembic/AbcCoreOgawa/All.h>

#include <fstream>

struct Main;
struct Scene;

namespace blender::io::alembic {

/* Wrappers around input and output archives. The goal is to be able to use
 * streams so that unicode paths work on Windows (T49112), and to make sure that
 * the stream objects remain valid as long as the archives are open.
 */

class ArchiveReader {
  Alembic::Abc::IArchive m_archive;
  std::ifstream m_infile;
  std::vector<std::istream *> m_streams;

 public:
  ArchiveReader(struct Main *bmain, const char *filename);

  bool valid() const;

  Alembic::Abc::IObject getTop();
};

}  // namespace blender::io::alembic
