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
struct wmKeyConfig;

/* lattice_ops.c */
void ED_operatortypes_lattice(void);
void ED_keymap_lattice(struct wmKeyConfig *keyconf);

/* editlattice_select.c */
bool ED_lattice_flags_set(struct Object *obedit, int flag);
bool ED_lattice_select_pick(
    struct bContext *C, const int mval[2], bool extend, bool deselect, bool toggle);

bool ED_lattice_deselect_all_multi_ex(struct Base **bases, const uint bases_len);
bool ED_lattice_deselect_all_multi(struct bContext *C);

/* editlattice_undo.c */
void ED_lattice_undosys_type(struct UndoType *ut);

#ifdef __cplusplus
}
#endif
