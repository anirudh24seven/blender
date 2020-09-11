#pragma once

/** \file
 * \ingroup balembic
 */

#include "abc_reader_object.h"

#include <Alembic/AbcGeom/All.h>

namespace blender::io::alembic {

class AbcEmptyReader : public AbcObjectReader {
  Alembic::AbcGeom::IXformSchema m_schema;

 public:
  AbcEmptyReader(const Alembic::Abc::IObject &object, ImportSettings &settings);

  bool valid() const;
  bool accepts_object_type(const Alembic::AbcCoreAbstract::ObjectHeader &alembic_header,
                           const Object *const ob,
                           const char **err_str) const;

  void readObjectData(Main *bmain, const Alembic::Abc::ISampleSelector &sample_sel);
};

}  // namespace blender::io::alembic
