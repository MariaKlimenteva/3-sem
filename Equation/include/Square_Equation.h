//=============================================================================

#ifndef SQUARE_EQUATION_H
#define SQUARE_EQUATION_H

#include <stdio.h>
#include <math.h>

#include "Enter_Coefficients.h"
#include "Comp_Eps.h"

enum number_of_roots
{
    ONE_ROOT  =  1,
    TWO_ROOTS =  2,
    ZERO_ROOTS = 0,
    INF_ROOTS =  3
};

//-----------------------------------------------------------------------------
//! @brief Solve quadratic equation
//!
//! @param [in] a - the coefficient at x^2 in the quadratic equation
//!
//! @param [in] b - the coefficient at x in the quadratic equation
//!
//! @param [in] c - free term in the quadratic equation
//!
//! @param [out] x1 - the first root of the quadratic equation
//!
//! @param [out] x2 - the second root of the quadratic equation
//!
//! @return What the functions linear_equation and square_equation return, i.e. the number of roots
//-----------------------------------------------------------------------------
int solve_quadratic_equation (double a, double b, double c, double *x1, double *x2);

//-----------------------------------------------------------------------------
//! @brief Solve the linear equation (a = 0)
//!
//! @param [in] b - the coefficient at x in the linear equation (bx + c = 0)
//!
//! @param [in] c - free term in the linear equation (bx + c = 0)
//!
//! @param [out] x1 - root of the linear equation
//!
//! @return The number of roots of linear equation
//-----------------------------------------------------------------------------
double linear_equation (double b, double c, double *x1);

//-----------------------------------------------------------------------------
//! @brief Solve equation through the discriminant
//!
//! @param [in] a - the coefficient at x^2 in the quadratic equation
//!
//! @param [in] b - the coefficient at x in the quadratic equation
//!
//! @param [in] c - free term in the quadratic equation
//!
//! @param [out] x1 - the first root of the quadratic equation
//!
//! @param [out] x2 - the second root of the quadratic equation
//!
//! @return The number of roots of square equation
//-----------------------------------------------------------------------------
int solution_by_discriminant (double a, double b, double c, double *x1, double *x2);

//-----------------------------------------------------------------------------
//! @brief Compare doubles with zero
//!
//! @param [in] value - a double number, which is compared with zero
//-----------------------------------------------------------------------------
bool is_zero(double value);

//-----------------------------------------------------------------------------
//! @brief Remove a number from the value minus zero
//!
//! @param [in] x - a number, that should be zero 
//-----------------------------------------------------------------------------
void destroy_minus_zero(double x);


#endif // SQUARE_EQUATION_H
