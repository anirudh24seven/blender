#include "NOD_node_tree_dependencies.hh"

#include "DNA_node_types.h"

#include "BKE_node.h"

namespace blender::nodes {

static void add_dependencies_of_node_tree(bNodeTree &ntree, NodeTreeDependencies &r_dependencies)
{
  /* TODO: Do a bit more sophisticated parsing to see which dependencies are really required. */
  LISTBASE_FOREACH (bNode *, node, &ntree.nodes) {
    LISTBASE_FOREACH (bNodeSocket *, socket, &node->inputs) {
      if (socket->type == SOCK_OBJECT) {
        Object *object = reinterpret_cast<bNodeSocketValueObject *>(socket->default_value)->value;
        if (object != nullptr) {
          r_dependencies.add_transform_dependency(object);
          if (object->type == OB_MESH) {
            r_dependencies.add_geometry_dependency(object);
          }
        }
      }
    }

    if (node->type == NODE_GROUP) {
      bNodeTree *group = reinterpret_cast<bNodeTree *>(node->id);
      if (group != nullptr) {
        add_dependencies_of_node_tree(*group, r_dependencies);
      }
    }
  }
}

NodeTreeDependencies find_node_tree_dependencies(bNodeTree &ntree)
{
  NodeTreeDependencies dependencies;
  add_dependencies_of_node_tree(ntree, dependencies);
  return dependencies;
}

}  // namespace blender::nodes
