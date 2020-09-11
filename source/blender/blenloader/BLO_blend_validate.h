#pragma once

/** \file
 * \ingroup blenloader
 * \brief Utils ensuring .blend file (i.e. Main)
 * is in valid state during write and/or read process.
 */

struct Main;
struct ReportList;

bool BLO_main_validate_libraries(struct Main *bmain, struct ReportList *reports);
bool BLO_main_validate_shapekeys(struct Main *bmain, struct ReportList *reports);
