/** \file
 * \ingroup depsgraph
 */

#pragma once

#include "pipeline.h"

namespace blender {
namespace deg {

class RenderBuilderPipeline : public AbstractBuilderPipeline {
 public:
  RenderBuilderPipeline(::Depsgraph *graph);

 protected:
  virtual void build_nodes(DepsgraphNodeBuilder &node_builder) override;
  virtual void build_relations(DepsgraphRelationBuilder &relation_builder) override;
};

}  // namespace deg
}  // namespace blender
