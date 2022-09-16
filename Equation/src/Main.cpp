//=============================================================================
//! @brief Calculating the roots of a quadratic equation
//!
//! @author Klimenteva Maria (https://github.com/MariaKlimenteva/MIPT_Huawei_course/tree/main/Equation)
//! @file Main.cpp
//! @date 27.08.2022
//!
//! @copyright Copyright (c) 2022
//-----------------------------------------------------------------------------
#include <assert.h>

#include "Square_Equation.h"
#include "Unit_Tests.h"
//-----------------------------------------------------------------------------
void output (int roots, double x1, double x2);
//-----------------------------------------------------------------------------
int main ()
{
    srand(time(0));

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    int roots = 0;

    int test_roots = 0;
    double test_x1 = 0, test_x2 = 0;

    unit_test_from_file (a, b, c, test_roots, test_x1, test_x2);

    enter_coefficients (&a, &b, &c);
    roots = solve_quadratic_equation (a, b, c, &x1, &x2);
    print_equation_solution (roots, x1, x2);

    return 0;
}

void print_equation_solution(enum number_of_roots roots, double x1, double x2)
{
    switch (roots)
    {
        case ONE_ROOT:

            printf ("One solution, x = %lf\n ", x1);
            break;

        case TWO_ROOTS:

            printf ("Two roots: x1 = %lf, x2 = %lf\n", x1, x2);
            break;

        case INF_ROOTS:

            printf ("Infinitely many solutions\n");
            break;

        case ZERO_ROOTS:

            printf ("There are no solutions\n");

            continue_troll();

            break;

        default:
            printf ("Error");
            assert(false && "Unreachable! Illegal roots' state!");
            break;
    }
}