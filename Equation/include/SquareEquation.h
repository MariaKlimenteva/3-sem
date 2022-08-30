//=============================================================================

// TODO: You surely can use custom naming in include guards, but this is a bit
//       confusing. Consider using file name instead: SQUARE_EQUATION_H. It's
//       much more common, much easier to support for tooling, and less likely
//       to cause a name collision.
#ifndef SQ_EQ_H
#define SQ_EQ_H

#include <stdio.h>
#include <math.h>

#include "Input.h"
#include "Comp_eps.h"

// TODO: Why do you write "function" in the begining of every docstring for
//       for your function? It's obvious anyway! Don't do this!

//       It's a much better idea to write about function's action in imperative
//       right away (it's also recomended by dozens of style guides)

// Exampli gratia:
// @brief Solve quadratic equation
//        ^~~~~~~~~~~~~~~~~~~~~~~~

//        Like this! No words like "algorithm", "function that solves"
//        Just pure meaning. Consider adopting everywhere!


//-----------------------------------------------------------------------------
//! @brief Function - algorithm for solving a quadratic equation
//!
//! @param [in] a, b, c - coefficients defining the quadratic equation ax^2 + bx + c = 0
//  TODO:       ^  ^  ^ all parameters should have a separate @param
//!
//! @param [out] x1, x2 - roots of the quadratic equation
//  TODO:        ^   ^  should be placed on different lines 
//!
//! @return What the functions linear_equation and square_equation return, i.e. the number of roots
//-----------------------------------------------------------------------------
int solve_quadratic_equation (double a, double b, double c, double *x1, double *x2);
// TODO: the distinction between square equation and solve_quadratic_equation
//       isn't obvious from the name to say the least!


//-----------------------------------------------------------------------------
//! @brief A function solving a linear equation, i.e. considering the case when a = 0
// TODO:   ^~~~~~~~~~ Obvious, delete! See top of the SquareEquation.h for details!
//!
//! @param [in] b, c - coefficients defining the linear equation bx + c = 0
//!
//! @param [out] x1 - root of the linear equation
//!
//! @return The number of roots of linear equation
//-----------------------------------------------------------------------------
double linear_equation (double b, double c, double *x1);
// TODO: Spaces aren't expensive, one extra line between function declarations
//       doesn't cost anything, yet improves readabily (here there was no space)
//-----------------------------------------------------------------------------
//! @brief A function that solves the discriminant and considers the case of matching roots
// TODO:   ^~~~~~~~~~ Obvious, delete! See top of the SquareEquation.h for details!
//!
//! @param [in] a, b, c - coefficients defining the square equation
//  TODO:       ^  ^  ^ should be placed on different lines 
//!
//! @param [out] x1, x2 - roots of the square equation
//  TODO:        ^   ^  should be placed on different lines 
//!
//! @return The number of roots of linear equation
//-----------------------------------------------------------------------------
int square_equation (double a, double b, double c, double *x1, double *x2);
// TODO: the distinction between square equation and solve_quadratic_equation
//       isn't obvious from the name to say the least!

#endif // SQ_EQ_H
