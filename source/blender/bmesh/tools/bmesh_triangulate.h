/** \file
 * \ingroup bmesh
 *
 * Triangulate.
 */

#pragma once

void BM_mesh_triangulate(BMesh *bm,
                         const int quad_method,
                         const int ngon_method,
                         const int min_vertices,
                         const bool tag_only,
                         BMOperator *op,
                         BMOpSlot *slot_facemap_out,
                         BMOpSlot *slot_facemap_double_out);
