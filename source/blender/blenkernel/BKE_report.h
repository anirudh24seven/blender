#pragma once

/** \file
 * \ingroup bke
 */

#include <stdio.h>

#include "BLI_compiler_attrs.h"
#include "BLI_utildefines.h"
#include "DNA_windowmanager_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Reporting Information and Errors
 *
 * These functions also accept NULL in case no error reporting
 * is needed. */

/* report structures are stored in DNA */

void BKE_reports_init(ReportList *reports, int flag);
void BKE_reports_clear(ReportList *reports);

void BKE_report(ReportList *reports, ReportType type, const char *message);
void BKE_reportf(ReportList *reports, ReportType type, const char *format, ...)
    ATTR_PRINTF_FORMAT(3, 4);

void BKE_reports_prepend(ReportList *reports, const char *prepend);
void BKE_reports_prependf(ReportList *reports, const char *prepend, ...) ATTR_PRINTF_FORMAT(2, 3);

ReportType BKE_report_print_level(ReportList *reports);
void BKE_report_print_level_set(ReportList *reports, ReportType level);

ReportType BKE_report_store_level(ReportList *reports);
void BKE_report_store_level_set(ReportList *reports, ReportType level);

char *BKE_reports_string(ReportList *reports, ReportType level);
void BKE_reports_print(ReportList *reports, ReportType level);

Report *BKE_reports_last_displayable(ReportList *reports);

bool BKE_reports_contain(ReportList *reports, ReportType level);

const char *BKE_report_type_str(ReportType type);

bool BKE_report_write_file_fp(FILE *fp, ReportList *reports, const char *header);
bool BKE_report_write_file(const char *filepath, ReportList *reports, const char *header);

#ifdef __cplusplus
}
#endif
