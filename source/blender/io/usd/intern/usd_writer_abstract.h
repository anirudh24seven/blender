/** The Original Code is Copyright (C) 2019 Blender Foundation.
 * All rights reserved.
 */
#pragma once

#include "IO_abstract_hierarchy_iterator.h"
#include "usd_exporter_context.h"

#include <pxr/usd/sdf/path.h>
#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usdShade/material.h>
#include <pxr/usd/usdUtils/sparseValueWriter.h>

#include <vector>

#include "DEG_depsgraph_query.h"

#include "DNA_material_types.h"

struct Material;
struct Object;

namespace blender::io::usd {

using blender::io::AbstractHierarchyWriter;
using blender::io::HierarchyContext;

class USDAbstractWriter : public AbstractHierarchyWriter {
 protected:
  const USDExporterContext usd_export_context_;
  pxr::UsdUtilsSparseValueWriter usd_value_writer_;

  bool frame_has_been_written_;
  bool is_animated_;

 public:
  USDAbstractWriter(const USDExporterContext &usd_export_context);
  virtual ~USDAbstractWriter();

  virtual void write(HierarchyContext &context) override;

  /* Returns true if the data to be written is actually supported. This would, for example, allow a
   * hypothetical camera writer accept a perspective camera but reject an orthogonal one.
   *
   * Returning false from a transform writer will prevent the object and all its descendants from
   * being exported. Returning false from a data writer (object data, hair, or particles) will
   * only prevent that data from being written (and thus cause the object to be exported as an
   * Empty). */
  virtual bool is_supported(const HierarchyContext *context) const;

  const pxr::SdfPath &usd_path() const;

 protected:
  virtual void do_write(HierarchyContext &context) = 0;
  pxr::UsdTimeCode get_export_time_code() const;

  pxr::UsdShadeMaterial ensure_usd_material(Material *material);

  void write_visibility(const HierarchyContext &context,
                        const pxr::UsdTimeCode timecode,
                        pxr::UsdGeomImageable &usd_geometry);

  /* Turn `prim` into an instance referencing `context.original_export_path`.
   * Return true when the instancing was successful, false otherwise. */
  virtual bool mark_as_instance(const HierarchyContext &context, const pxr::UsdPrim &prim);
};

}  // namespace blender::io::usd
