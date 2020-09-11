/** \file
 * \ingroup editors
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct KDTree_1d;

enum {
  SEL_TOGGLE = 0,
  SEL_SELECT = 1,
  SEL_DESELECT = 2,
  SEL_INVERT = 3,
};

typedef enum WalkSelectDirection {
  UI_SELECT_WALK_UP,
  UI_SELECT_WALK_DOWN,
  UI_SELECT_WALK_LEFT,
  UI_SELECT_WALK_RIGHT,
} WalkSelectDirections;

/** See #WM_operator_properties_select_operation */
typedef enum {
  SEL_OP_ADD = 1,
  SEL_OP_SUB,
  SEL_OP_SET,
  SEL_OP_AND,
  SEL_OP_XOR,
} eSelectOp;

/* Select Similar */
enum {
  SIM_CMP_EQ = 0,
  SIM_CMP_GT,
  SIM_CMP_LT,
};

#define SEL_OP_USE_OUTSIDE(sel_op) (ELEM(sel_op, SEL_OP_AND))
#define SEL_OP_USE_PRE_DESELECT(sel_op) (ELEM(sel_op, SEL_OP_SET))
#define SEL_OP_CAN_DESELECT(sel_op) (!ELEM(sel_op, SEL_OP_ADD))

/* Use when we've de-selected all first for 'SEL_OP_SET' */
int ED_select_op_action(const eSelectOp sel_op, const bool is_select, const bool is_inside);
int ED_select_op_action_deselected(const eSelectOp sel_op,
                                   const bool is_select,
                                   const bool is_inside);

int ED_select_similar_compare_float(const float delta, const float thresh, const int compare);
bool ED_select_similar_compare_float_tree(const struct KDTree_1d *tree,
                                          const float length,
                                          const float thresh,
                                          const int compare);

eSelectOp ED_select_op_modal(const eSelectOp sel_op, const bool is_first);

#ifdef __cplusplus
}
#endif
