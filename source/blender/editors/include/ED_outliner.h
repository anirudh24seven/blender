/** The Original Code is Copyright (C) 2015, Blender Foundation
 */

/** \file
 * \ingroup editors
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct Base;
struct ListBase;
struct SpaceOutliner;
struct bContext;

bool ED_outliner_collections_editor_poll(struct bContext *C);

void ED_outliner_selected_objects_get(const struct bContext *C, struct ListBase *objects);

struct Base *ED_outliner_give_base_under_cursor(struct bContext *C, const int mval[2]);

void ED_outliner_select_sync_from_object_tag(struct bContext *C);
void ED_outliner_select_sync_from_edit_bone_tag(struct bContext *C);
void ED_outliner_select_sync_from_pose_bone_tag(struct bContext *C);
void ED_outliner_select_sync_from_sequence_tag(struct bContext *C);
void ED_outliner_select_sync_from_all_tag(struct bContext *C);

bool ED_outliner_select_sync_is_dirty(const struct bContext *C);

void ED_outliner_select_sync_from_outliner(struct bContext *C,
                                           struct SpaceOutliner *space_outliner);

void ED_outliner_select_sync_flag_outliners(const struct bContext *C);

#ifdef __cplusplus
}
#endif
