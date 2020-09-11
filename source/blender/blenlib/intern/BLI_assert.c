/** \file
 * \ingroup bli
 *
 * Helper functions for BLI_assert.h header.
 */

#include "BLI_assert.h" /* Own include. */
#include "BLI_system.h"

#include <stdio.h>
#include <stdlib.h>

void _BLI_assert_print_pos(const char *file, const int line, const char *function, const char *id)
{
  fprintf(stderr, "BLI_assert failed: %s:%d, %s(), at \'%s\'\n", file, line, function, id);
}

void _BLI_assert_print_backtrace(void)
{
#ifndef NDEBUG
  BLI_system_backtrace(stderr);
#endif
}

/**
 * Wrap to remove 'noreturn' attribute since this suppresses missing return statements,
 * allowing changes to debug builds to accidentally to break release builds.
 *
 * For example `BLI_assert(0);` at the end of a function that returns a value,
 * will hide that it's missing a return.
 */
void _BLI_assert_abort(void)
{
  abort();
}
