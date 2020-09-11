/** The Original Code is Copyright (C) 2016 Kévin Dietrich.
 * All rights reserved.
 */
#pragma once

/** \file
 * \ingroup balembic
 */

#include "abc_reader_mesh.h"
#include "abc_reader_object.h"

struct Curve;

#define ABC_CURVE_RESOLUTION_U_PROPNAME "blender:resolution"

namespace blender::io::alembic {

class AbcCurveReader : public AbcObjectReader {
  Alembic::AbcGeom::ICurvesSchema m_curves_schema;

 public:
  AbcCurveReader(const Alembic::Abc::IObject &object, ImportSettings &settings);

  bool valid() const;
  bool accepts_object_type(const Alembic::AbcCoreAbstract::ObjectHeader &alembic_header,
                           const Object *const ob,
                           const char **err_str) const;

  void readObjectData(Main *bmain, const Alembic::Abc::ISampleSelector &sample_sel);
  struct Mesh *read_mesh(struct Mesh *existing_mesh,
                         const Alembic::Abc::ISampleSelector &sample_sel,
                         int read_flag,
                         const char **err_str);

  void read_curve_sample(Curve *cu,
                         const Alembic::AbcGeom::ICurvesSchema &schema,
                         const Alembic::Abc::ISampleSelector &sample_selector);
};

}  // namespace blender::io::alembic
