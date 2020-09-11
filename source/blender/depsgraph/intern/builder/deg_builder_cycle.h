/** \file
 * \ingroup depsgraph
 */

#pragma once

namespace blender {
namespace deg {

struct Depsgraph;

/* Detect and solve dependency cycles. */
void deg_graph_detect_cycles(Depsgraph *graph);

}  // namespace deg
}  // namespace blender
