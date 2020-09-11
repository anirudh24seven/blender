/** \file
 * \ingroup bke
 */

#include "BLI_listbase.h"
#include "BLI_utildefines.h"

#include "BKE_callbacks.h"

#include "MEM_guardedalloc.h"

#include "RNA_access.h"
#include "RNA_types.h"

static ListBase callback_slots[BKE_CB_EVT_TOT] = {{NULL}};

void BKE_callback_exec(struct Main *bmain,
                       struct PointerRNA **pointers,
                       const int num_pointers,
                       eCbEvent evt)
{
  ListBase *lb = &callback_slots[evt];
  bCallbackFuncStore *funcstore;

  for (funcstore = lb->first; funcstore; funcstore = funcstore->next) {
    funcstore->func(bmain, pointers, num_pointers, funcstore->arg);
  }
}

void BKE_callback_exec_null(struct Main *bmain, eCbEvent evt)
{
  BKE_callback_exec(bmain, NULL, 0, evt);
}

void BKE_callback_exec_id(struct Main *bmain, struct ID *id, eCbEvent evt)
{
  PointerRNA id_ptr;
  RNA_id_pointer_create(id, &id_ptr);

  PointerRNA *pointers[1] = {&id_ptr};

  BKE_callback_exec(bmain, pointers, 1, evt);
}

void BKE_callback_exec_id_depsgraph(struct Main *bmain,
                                    struct ID *id,
                                    struct Depsgraph *depsgraph,
                                    eCbEvent evt)
{
  PointerRNA id_ptr;
  RNA_id_pointer_create(id, &id_ptr);

  PointerRNA depsgraph_ptr;
  RNA_pointer_create(NULL, &RNA_Depsgraph, depsgraph, &depsgraph_ptr);

  PointerRNA *pointers[2] = {&id_ptr, &depsgraph_ptr};

  BKE_callback_exec(bmain, pointers, 2, evt);
}

void BKE_callback_add(bCallbackFuncStore *funcstore, eCbEvent evt)
{
  ListBase *lb = &callback_slots[evt];
  BLI_addtail(lb, funcstore);
}

void BKE_callback_global_init(void)
{
  /* do nothing */
}

/* call on application exit */
void BKE_callback_global_finalize(void)
{
  eCbEvent evt;
  for (evt = 0; evt < BKE_CB_EVT_TOT; evt++) {
    ListBase *lb = &callback_slots[evt];
    bCallbackFuncStore *funcstore;
    bCallbackFuncStore *funcstore_next;
    for (funcstore = lb->first; funcstore; funcstore = funcstore_next) {
      funcstore_next = funcstore->next;
      BLI_remlink(lb, funcstore);
      if (funcstore->alloc) {
        MEM_freeN(funcstore);
      }
    }
  }
}
