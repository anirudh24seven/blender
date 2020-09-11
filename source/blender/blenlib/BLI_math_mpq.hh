#pragma once

/** \file
 * \ingroup bli
 */

#ifdef WITH_GMP

/* This file uses an external file header to define the multi-precision
 * rational type, mpq_class.
 * This class keeps separate multi-precision integer numerator and
 * denominator, reduced to lowest terms after each arithmetic operation.
 * It can be used where it is important to have exact arithmetic results.
 *
 * See gmplib.org for full documentation. In particular:
 * https://gmplib.org/manual/C_002b_002b-Interface-Rationals
 */
#  include "gmpxx.h"

#endif /* WITH_GMP */
