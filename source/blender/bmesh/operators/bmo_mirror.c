/** \file
 * \ingroup bmesh
 *
 * Basic mirror, optionally with UVs's.
 */

#include "MEM_guardedalloc.h"

#include "DNA_meshdata_types.h"

#include "BLI_math.h"

#include "BKE_customdata.h"

#include "bmesh.h"
#include "intern/bmesh_operators_private.h" /* own include */

#define ELE_NEW 1

void bmo_mirror_exec(BMesh *bm, BMOperator *op)
{
  BMOperator dupeop, weldop;
  BMOIter siter;
  BMIter iter;
  BMVert *v, **vmap;
  int vmap_size = 0;
  float mtx[4][4];
  float imtx[4][4];
  float scale[3] = {1.0f, 1.0f, 1.0f};
  float dist = BMO_slot_float_get(op->slots_in, "merge_dist");
  int i, ototvert;
  int axis = BMO_slot_int_get(op->slots_in, "axis");
  bool mirror_u = BMO_slot_bool_get(op->slots_in, "mirror_u");
  bool mirror_v = BMO_slot_bool_get(op->slots_in, "mirror_v");
  bool mirror_udim = BMO_slot_bool_get(op->slots_in, "mirror_udim");
  BMOpSlot *slot_targetmap;

  ototvert = bm->totvert;

  BMO_slot_mat4_get(op->slots_in, "matrix", mtx);
  invert_m4_m4(imtx, mtx);

  BMO_op_initf(bm, &dupeop, op->flag, "duplicate geom=%s", op, "geom");
  BMO_op_exec(bm, &dupeop);

  BMO_slot_buffer_flag_enable(bm, dupeop.slots_out, "geom.out", BM_ALL_NOLOOP, ELE_NEW);

  /* create old -> new mappin */
  vmap = BMO_iter_as_arrayN(dupeop.slots_out, "geom.out", BM_VERT, &vmap_size, NULL, 0);

  /* feed old data to transform bmo */
  scale[axis] = -1.0f;
  BMO_op_callf(bm, op->flag, "transform verts=%fv matrix=%m4", ELE_NEW, mtx);
  BMO_op_callf(bm, op->flag, "scale verts=%fv vec=%v", ELE_NEW, scale);
  BMO_op_callf(bm, op->flag, "transform verts=%fv matrix=%m4", ELE_NEW, imtx);

  BMO_op_init(bm, &weldop, op->flag, "weld_verts");

  slot_targetmap = BMO_slot_get(weldop.slots_in, "targetmap");

  v = BM_iter_new(&iter, bm, BM_VERTS_OF_MESH, NULL);
  for (i = 0; i < ototvert; i++) {
    if (fabsf(v->co[axis]) <= dist) {
      BLI_assert(vmap_size >= i);
      BMO_slot_map_elem_insert(&weldop, slot_targetmap, vmap[i], v);
    }
    v = BM_iter_step(&iter);
  }

  if (mirror_u || mirror_v) {
    BMFace *f;
    BMLoop *l;
    MLoopUV *luv;
    const int totlayer = CustomData_number_of_layers(&bm->ldata, CD_MLOOPUV);
    BMIter liter;

    BMO_ITER (f, &siter, dupeop.slots_out, "geom.out", BM_FACE) {
      BM_ITER_ELEM (l, &liter, f, BM_LOOPS_OF_FACE) {
        for (i = 0; i < totlayer; i++) {
          luv = CustomData_bmesh_get_n(&bm->ldata, l->head.data, CD_MLOOPUV, i);
          if (mirror_u) {
            float uv_u = luv->uv[0];
            if (mirror_udim) {
              luv->uv[0] = ceilf(uv_u) - fmodf(uv_u, 1.0f);
            }
            else {
              luv->uv[0] = 1.0f - uv_u;
            }
          }
          if (mirror_v) {
            float uv_v = luv->uv[1];
            if (mirror_udim) {
              luv->uv[1] = ceilf(uv_v) - fmodf(uv_v, 1.0f);
            }
            else {
              luv->uv[1] = 1.0f - uv_v;
            }
          }
        }
      }
    }
  }

  BMO_op_exec(bm, &weldop);

  BMO_op_finish(bm, &weldop);
  BMO_op_finish(bm, &dupeop);

  BMO_slot_buffer_from_enabled_flag(bm, op, op->slots_out, "geom.out", BM_ALL_NOLOOP, ELE_NEW);

  if (vmap) {
    MEM_freeN(vmap);
  }
}
