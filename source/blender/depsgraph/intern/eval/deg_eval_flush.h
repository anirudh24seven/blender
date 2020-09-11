/** \file
 * \ingroup depsgraph
 *
 * Core routines for how the Depsgraph works.
 */

#pragma once

struct Main;

namespace blender {
namespace deg {

struct Depsgraph;

/* Flush updates from tagged nodes outwards until all affected nodes
 * are tagged.
 */
void deg_graph_flush_updates(struct Depsgraph *graph);

/* Clear tags from all operation nodes. */
void deg_graph_clear_tags(struct Depsgraph *graph);

}  // namespace deg
}  // namespace blender
