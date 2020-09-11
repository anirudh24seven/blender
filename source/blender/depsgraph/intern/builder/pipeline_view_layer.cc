#include "pipeline_view_layer.h"

#include "intern/builder/deg_builder_nodes.h"
#include "intern/builder/deg_builder_relations.h"
#include "intern/depsgraph.h"

namespace blender {
namespace deg {

ViewLayerBuilderPipeline::ViewLayerBuilderPipeline(::Depsgraph *graph)
    : AbstractBuilderPipeline(graph)
{
}

void ViewLayerBuilderPipeline::build_nodes(DepsgraphNodeBuilder &node_builder)
{
  node_builder.build_view_layer(scene_, view_layer_, DEG_ID_LINKED_DIRECTLY);
}

void ViewLayerBuilderPipeline::build_relations(DepsgraphRelationBuilder &relation_builder)
{
  relation_builder.build_view_layer(scene_, view_layer_, DEG_ID_LINKED_DIRECTLY);
}

}  // namespace deg
}  // namespace blender
