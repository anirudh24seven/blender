#pragma once

/** \file
 * \ingroup balembic
 */

#include "abc_writer_abstract.h"

namespace blender::io::alembic {

/* Writer for Alembic instances, i.e. data that references another Alembic object.
 *
 * Note that the Alembic object created by this writer cannot be used as a
 * parent, because it already instantiates the entire hierarchy of the
 * referenced object. */
class ABCInstanceWriter : public ABCAbstractWriter {
 public:
  explicit ABCInstanceWriter(const ABCWriterConstructorArgs &args);
  virtual ~ABCInstanceWriter();

  virtual void create_alembic_objects(const HierarchyContext *context) override;
  virtual Alembic::Abc::OObject get_alembic_object() const override;

 protected:
  virtual bool is_supported(const HierarchyContext *context) const override;
  virtual void do_write(HierarchyContext &context) override;
};

}  // namespace blender::io::alembic
