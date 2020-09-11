/** \file
 * \ingroup editors
 */

#pragma once

#include "BLI_compiler_attrs.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Main;
struct bContext;
struct wmOperatorType;

/* ed_util.c */
void ED_editors_init_for_undo(struct Main *bmain);
void ED_editors_init(struct bContext *C);
void ED_editors_exit(struct Main *bmain, bool do_undo_system);

bool ED_editors_flush_edits_for_object_ex(struct Main *bmain,
                                          struct Object *ob,
                                          bool for_render,
                                          bool check_needs_flush);
bool ED_editors_flush_edits_for_object(struct Main *bmain, struct Object *ob);

bool ED_editors_flush_edits_ex(struct Main *bmain, bool for_render, bool check_needs_flush);
bool ED_editors_flush_edits(struct Main *bmain);

void ED_spacedata_id_remap(struct ScrArea *area,
                           struct SpaceLink *sl,
                           struct ID *old_id,
                           struct ID *new_id);

void ED_OT_flush_edits(struct wmOperatorType *ot);

/* ************** XXX OLD CRUFT WARNING ************* */

void apply_keyb_grid(
    int shift, int ctrl, float *val, float fac1, float fac2, float fac3, int invert);

/* where else to go ? */
void unpack_menu(struct bContext *C,
                 const char *opname,
                 const char *id_name,
                 const char *abs_name,
                 const char *folder,
                 struct PackedFile *pf);

#ifdef __cplusplus
}
#endif
