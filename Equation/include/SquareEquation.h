//=============================================================================
#ifndef SQ_EQ_H
#define SQ_EQ_H

#include <stdio.h>
#include <math.h>

#include "Input.h"
#include "Comp_eps.h"
//-----------------------------------------------------------------------------
//! @brief Function - algorithm for solving a quadratic equation
//!
//! @param [in] a, b, c - coefficients defining the quadratic equation ax^2 + bx + c = 0
//!
//! @param [out] x1, x2 - roots of the quadratic equation
//!
//! @return What the functions linear_equation and square_equation return, i.e. the number of roots
//-----------------------------------------------------------------------------
int solve_quadratic_equation (double a, double b, double c, double *x1, double *x2);
//-----------------------------------------------------------------------------
//! @brief A function solving a linear equation, i.e. considering the case when a = 0
//!
//! @param [in] b, c - coefficients defining the linear equation bx + c = 0
//!
//! @param [out] x1 - root of the linear equation
//!
//! @return The number of roots of linear equation
//-----------------------------------------------------------------------------
double linear_equation (double b, double c, double *x1);
//-----------------------------------------------------------------------------
//! @brief A function that solves the discriminant and considers the case of matching roots
//!
//! @param [in] a, b, c - coefficients defining the square equation
//!
//! @param [out] x1, x2 - roots of the square equation
//!
//! @return The number of roots of linear equation
//-----------------------------------------------------------------------------
int square_equation (double a, double b, double c, double *x1, double *x2);

#endif // SQ_EQ_H
