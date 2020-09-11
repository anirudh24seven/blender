#pragma once

/** \file
 * \ingroup bmesh
 */

void BMO_mesh_delete_oflag_tagged(BMesh *bm, const short oflag, const char htype);
void BM_mesh_delete_hflag_tagged(BMesh *bm, const char hflag, const char htype);

void BMO_mesh_delete_oflag_context(BMesh *bm, const short oflag, const int type);
void BM_mesh_delete_hflag_context(BMesh *bm, const char hflag, const int type);
