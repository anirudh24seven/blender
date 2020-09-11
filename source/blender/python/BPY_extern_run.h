/** \file
 * \ingroup python
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "BLI_sys_types.h"

struct ReportList;
struct Text;
struct bContext;

/* bpy_interface_run.c */
bool BPY_run_filepath(struct bContext *C, const char *filepath, struct ReportList *reports);
bool BPY_run_text(struct bContext *C,
                  struct Text *text,
                  struct ReportList *reports,
                  const bool do_jump);

/* Use the 'eval' for simple single-line expressions,
 * otherwise 'exec' for full multi-line scripts. */
bool BPY_run_string_exec(struct bContext *C, const char *imports[], const char *expr);
bool BPY_run_string_eval(struct bContext *C, const char *imports[], const char *expr);

/* Run, evaluating to fixed type result. */
bool BPY_run_string_as_number(struct bContext *C,
                              const char *imports[],
                              const char *expr,
                              const char *report_prefix,
                              double *r_value);
bool BPY_run_string_as_intptr(struct bContext *C,
                              const char *imports[],
                              const char *expr,
                              const char *report_prefix,
                              intptr_t *r_value);
bool BPY_run_string_as_string_and_size(struct bContext *C,
                                       const char *imports[],
                                       const char *expr,
                                       const char *report_prefix,
                                       char **r_value,
                                       size_t *r_value_size);
bool BPY_run_string_as_string(struct bContext *C,
                              const char *imports[],
                              const char *expr,
                              const char *report_prefix,
                              char **r_value);

#ifdef __cplusplus
} /* extern "C" */
#endif
