
#include <assert.h>

#include "../include/SquareEquation.h"
#include "../include/utils.h"

// TODO: Read corresponding header file first!

int solve_quadratic_equation (double a, double b, double c, double *x1, double *x2)
{
    // TODO: What if any of coefficients is NAN or INF or x1 == x2? x1 == NULL, ...?
    //       Assert and document!

    if (comp_eps(a, 0)) // TODO: Used multitude of times, extract in function is_zero
    {
       return linear_equation (b, c, x1);
    }
    else
    {
        return square_equation (a, b, c, x1, x2);
    }
}

double linear_equation (double b, double c, double *x1)
{
    // TODO: See solve_quadratic_equation
    assert(x1 != nullptr);

    if (comp_eps(b, 0))
    {
        if (comp_eps(c, 0))
        {
            return INF_ROOTS;
        }
        else
        {
            return ZERO_ROOT;
        }
    }
    else
    {
        *x1 = -c/b;

        // TODO: Commented code, interesting!
        /*if (comp_eps(*x1, 0))
        {
            *x1 = 0;
        }*/

        if (Debug) printf ("%lg !!!, line = %d\n", *x1, __LINE__);
        // ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TODO: Eh, macro!

        return ONE_ROOT;
    }
}

int square_equation (double a, double b, double c, double *x1, double *x2)
{
    // TODO: See solve_quadratic_equation
    assert(x1 != nullptr);
    assert(x2 != nullptr);

    double double_a = 2*a;
    //     ^~~~~~ TODO: Name is confusing because of existance of type named the same way!
    //                  You can use a_doubled or two_times_a instead, and confusion is gone!

    double Discr = b*b - 2*double_a*c;
// TODO:   ^ Naming? Also, why discr not discriminant, a few extra letters won't hurt!

    if (Debug) printf ("%lg, line = %d\n", Discr, __LINE__);
    // TODO: ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Extract!

    // TODO: Isn't this an elaborate a way to say Discr < 0?
    //       Should probably split D = 0 and D < 0 cases for better perfomance.

    //       And, maybe, even consider separately
    //       some other corner cases (such as x^2 - x = 0)
    if (comp_eps (Discr, 0) || (Discr > 0))
    {
        *x1 = -(b - sqrt(Discr)) / double_a;
        *x2 = -(b + sqrt(Discr)) / double_a;

        if (comp_eps(*x1, 0))
        {
            *x1 = 0;
        }
        if (comp_eps(*x2, 0)) // TODO: Repeated to times. Extract to function.
        {
            *x2 = 0;
        }

        if (comp_eps((*x1 - *x2), 0))
        { // TODO:   ^~~~~~~~~, would be unnecessary if you considered two cases separately
            return ONE_ROOT;
        }
        else // TODO: else after return
        {
            if ((comp_eps (*x1, 0)) || (comp_eps (*x2, 0)))
            {
                return ONE_ROOT;
            }
            else return TWO_ROOTS; // TODO: else after return
            if (Debug) printf("%lg %lg, line = %d\n", *x1, *x2, __LINE__);
            // ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Extract!
        }
    }
    else
    {
        return ZERO_ROOT;
    }
}
