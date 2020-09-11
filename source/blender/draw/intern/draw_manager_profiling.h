/** \file
 * \ingroup draw
 */

#pragma once

struct rcti;

void DRW_stats_free(void);
void DRW_stats_begin(void);
void DRW_stats_reset(void);

void DRW_stats_group_start(const char *name);
void DRW_stats_group_end(void);

void DRW_stats_query_start(const char *name);
void DRW_stats_query_end(void);

void DRW_stats_draw(const rcti *rect);
