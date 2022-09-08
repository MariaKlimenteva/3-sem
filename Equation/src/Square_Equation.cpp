
#include <assert.h>

#include "Square_Equation.h"

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
        return solution_by_discriminant (a, b, c, x1, x2);
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
            return ZERO_ROOTS;
        }
    }
    else
    {
        *x1 = -c/b;
        return ONE_ROOT;
    }
}

int solution_by_discriminant (double a, double b, double c, double *x1, double *x2)
{
    // TODO: See solve_quadratic_equation
    assert(x1 != nullptr);
    assert(x2 != nullptr);

    double a_doubled = 2*a;

    double discriminant = b*b - 2*a_doubled*c;

    if (comp_eps (discriminant, 0))
    {
        *x1 = -b/a_doubled;
    }

    if (Discr > 0)
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
        }
    }

    if (discriminant < 0)
    {
        return ZERO_ROOTS;
    }
}
