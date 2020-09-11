/** \file
 * \ingroup depsgraph
 */

#pragma once

namespace blender {
namespace deg {

struct Depsgraph;

/* Remove all no-op nodes that have zero outgoing relations. */
void deg_graph_remove_unused_noops(Depsgraph *graph);

}  // namespace deg
}  // namespace blender
