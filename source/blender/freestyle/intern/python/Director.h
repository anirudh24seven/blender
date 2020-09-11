/** \file
 * \ingroup freestyle
 */

#pragma once

namespace Freestyle {
class UnaryPredicate0D;
class UnaryPredicate1D;
class BinaryPredicate0D;
class BinaryPredicate1D;
class ChainingIterator;
class AdjacencyIterator;
class Interface0D;
class Interface1D;
class Interface0DIterator;
class Stroke;
class StrokeShader;
}  // namespace Freestyle

using namespace Freestyle;

// BinaryPredicate0D: __call__
int Director_BPy_BinaryPredicate0D___call__(BinaryPredicate0D *bp0D,
                                            Interface0D &i1,
                                            Interface0D &i2);

// BinaryPredicate1D: __call__
int Director_BPy_BinaryPredicate1D___call__(BinaryPredicate1D *bp1D,
                                            Interface1D &i1,
                                            Interface1D &i2);

// UnaryFunction{0D,1D}: __call__
int Director_BPy_UnaryFunction0D___call__(void *uf0D, void *py_uf0D, Interface0DIterator &if0D_it);
int Director_BPy_UnaryFunction1D___call__(void *uf1D, void *py_uf1D, Interface1D &if1D);

// UnaryPredicate0D: __call__
int Director_BPy_UnaryPredicate0D___call__(UnaryPredicate0D *up0D, Interface0DIterator &if0D_it);

// UnaryPredicate1D: __call__
int Director_BPy_UnaryPredicate1D___call__(UnaryPredicate1D *up1D, Interface1D &if1D);

// StrokeShader: shade
int Director_BPy_StrokeShader_shade(StrokeShader *ss, Stroke &s);

// ChainingIterator: init, traverse
int Director_BPy_ChainingIterator_init(ChainingIterator *c_it);
int Director_BPy_ChainingIterator_traverse(ChainingIterator *c_it, AdjacencyIterator &a_it);
