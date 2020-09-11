#pragma once

/** \file
 * \ingroup balembic
 */

#include "abc_reader_object.h"

namespace blender::io::alembic {

class AbcNurbsReader : public AbcObjectReader {
  std::vector<std::pair<Alembic::AbcGeom::INuPatchSchema, Alembic::Abc::IObject>> m_schemas;

 public:
  AbcNurbsReader(const Alembic::Abc::IObject &object, ImportSettings &settings);

  bool valid() const;

  void readObjectData(Main *bmain, const Alembic::Abc::ISampleSelector &sample_sel);

 private:
  void getNurbsPatches(const Alembic::Abc::IObject &obj);
};

}  // namespace blender::io::alembic
