
//=============================================================================
//! @brief Вычисление корней квадратного уравнения
//!
//! @author Климентьева Мария (https://github.com/MariaKlimenteva/MIPT_Huawei_course/tree/main/Equation)
//! @file Main.cpp
//! @date 27.08.2022
//!
//! @copyright Copyright (c) 2022
//-----------------------------------------------------------------------------

#include <TXlib.h>

#include "SquareEquation/SquareEquation.h"
#include "utils.h"
#include "unit_tests/unit_tests.h"

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

    unit_Test_fromFile (a, b, c, test_roots, test_x1, test_x2);

    input (&a, &b, &c);
    roots = solve_quadratic_equation (a, b, c, &x1, &x2);
    output (roots, x1, x2);

    return 0;
}

//-----------------------------------------------------------------------------

void output (int roots, double x1, double x2)
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

        case ZERO_ROOT:

            printf ("There are no solutions\n");

            is_trolling();

            break;

        default:

            printf ("%d (Main.cpp)", roots);
            printf ("Error");
            break;
    }
}

