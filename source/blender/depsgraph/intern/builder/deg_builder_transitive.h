/** \file
 * \ingroup depsgraph
 */

#pragma once

namespace blender {
namespace deg {

struct Depsgraph;

/* Performs a transitive reduction to remove redundant relations. */
void deg_graph_transitive_reduction(Depsgraph *graph);

}  // namespace deg
}  // namespace blender
