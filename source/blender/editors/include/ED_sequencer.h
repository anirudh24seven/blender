/** The Original Code is Copyright (C) 2009, Blender Foundation
 */

/** \file
 * \ingroup editors
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct Scene;
struct Sequence;
struct SpaceSeq;
struct bContext;

void ED_sequencer_select_sequence_single(struct Scene *scene,
                                         struct Sequence *seq,
                                         bool deselect_all);
void ED_sequencer_deselect_all(struct Scene *scene);

bool ED_space_sequencer_maskedit_mask_poll(struct bContext *C);
bool ED_space_sequencer_check_show_maskedit(struct SpaceSeq *sseq, struct Scene *scene);
bool ED_space_sequencer_maskedit_poll(struct bContext *C);

bool ED_space_sequencer_check_show_imbuf(struct SpaceSeq *sseq);
bool ED_space_sequencer_check_show_strip(struct SpaceSeq *sseq);

void ED_operatormacros_sequencer(void);

Sequence *ED_sequencer_special_preview_get(void);
void ED_sequencer_special_preview_set(struct bContext *C, const int mval[2]);
void ED_sequencer_special_preview_clear(void);

#ifdef __cplusplus
}
#endif
