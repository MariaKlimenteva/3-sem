//=============================================================================
//! @brief Calculating the roots of a quadratic equation
//!
//! @author Klimenteva Maria (https://github.com/MariaKlimenteva/MIPT_Huawei_course/tree/main/Equation)
//! @file Main.cpp
//! @date 27.08.2022
//!
//! @copyright Copyright (c) 2022
//-----------------------------------------------------------------------------

// TODO: You don't even use it in here, yet still include! Delete!
// #include <TXlib.h>

// TODO: Never use relative paths to includes', use "-I <include-dir>" compiler flag,
//       to include by relative to specified directory path! 
#include "../include/SquareEquation.h"
#include "../include/utils.h"
#include "../include/unit_tests.h"
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
// TODO: Name "output" isn't descriptive. I couldn't tell what it does, before
//       I saw implementation. Not ideal!

//       A much better name would be something that puts emphasis on this
//       function's side effect (printing text to console) and purpose
//       (showing user a solution to equation).

//       For example, print_equation_solution would be a better name,
//       I hope you see why!

//       And for later, as a rule of thumb, use verbs for function names,
//       not nouns like you did here!

void output (int roots, double x1, double x2)
// TODO:     ^~~ you have a special enum for number of roots, why do you use
//           decayed version of it: int here instead of it? It would not only
//           add readabily to your code, but also give you a bunch of compiler
//           enforced goods. Strongly advised!
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
            // TODO: If this code is reached it's a pretty bad programmer
            //       error (there was a root's state that wasn't checked).

            //       And there is a specially utiliy in standard library for
            //       telling programmer about program's invariant violations (like such)
            //       ASAP. They are called asserts, use them (especially here!).

            printf ("%d (Main.cpp)", roots);
            printf ("Error");
            break;
    }
}

