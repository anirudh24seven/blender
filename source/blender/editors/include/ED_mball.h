/** \file
 * \ingroup editors
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct Base;
struct Object;
struct UndoType;
struct bContext;
struct wmKeyConfig;

void ED_operatortypes_metaball(void);
void ED_operatormacros_metaball(void);
void ED_keymap_metaball(struct wmKeyConfig *keyconf);

struct MetaElem *ED_mball_add_primitive(struct bContext *C,
                                        struct Object *obedit,
                                        bool obedit_is_new,
                                        float mat[4][4],
                                        float dia,
                                        int type);

bool ED_mball_select_pick(
    struct bContext *C, const int mval[2], bool extend, bool deselect, bool toggle);

bool ED_mball_deselect_all_multi_ex(struct Base **bases, uint bases_len);
bool ED_mball_deselect_all_multi(struct bContext *C);

void ED_mball_editmball_free(struct Object *obedit);
void ED_mball_editmball_make(struct Object *obedit);
void ED_mball_editmball_load(struct Object *obedit);

/* editmball_undo.c */
void ED_mball_undosys_type(struct UndoType *ut);

#define MBALLSEL_STIFF (1u << 30)
#define MBALLSEL_RADIUS (1u << 31)
#define MBALLSEL_ANY (MBALLSEL_STIFF | MBALLSEL_RADIUS)

#ifdef __cplusplus
}
#endif
