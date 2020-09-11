/** \file
 * \ingroup edtransform
 */

#pragma once

struct TransInfo;

void constraintNumInput(TransInfo *t, float vec[3]);
void transform_constraint_snap_axis_to_edge(const TransInfo *t,
                                            const float axis[3],
                                            float r_out[3]);
void transform_constraint_snap_axis_to_face(const TransInfo *t,
                                            const float axis[3],
                                            float r_out[3]);
void setConstraint(TransInfo *t, int mode, const char text[]);
void setAxisMatrixConstraint(TransInfo *t, int mode, const char text[]);
void setLocalConstraint(TransInfo *t, int mode, const char text[]);
void setUserConstraint(TransInfo *t, short orientation, int mode, const char text[]);
void drawConstraint(TransInfo *t);
void drawPropCircle(const struct bContext *C, TransInfo *t);
void startConstraint(TransInfo *t);
void stopConstraint(TransInfo *t);
void initSelectConstraint(TransInfo *t);
void selectConstraint(TransInfo *t);
void postSelectConstraint(TransInfo *t);
void setNearestAxis(TransInfo *t);
int constraintModeToIndex(const TransInfo *t);
char constraintModeToChar(const TransInfo *t);
bool isLockConstraint(TransInfo *t);
int getConstraintSpaceDimension(TransInfo *t);
