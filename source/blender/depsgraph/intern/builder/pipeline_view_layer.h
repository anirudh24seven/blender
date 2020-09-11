/** \file
 * \ingroup depsgraph
 */

#pragma once

#include "pipeline.h"

namespace blender {
namespace deg {

class ViewLayerBuilderPipeline : public AbstractBuilderPipeline {
 public:
  ViewLayerBuilderPipeline(::Depsgraph *graph);

 protected:
  virtual void build_nodes(DepsgraphNodeBuilder &node_builder) override;
  virtual void build_relations(DepsgraphRelationBuilder &relation_builder) override;
};

}  // namespace deg
}  // namespace blender
