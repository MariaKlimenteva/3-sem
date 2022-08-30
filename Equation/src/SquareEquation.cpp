
#include <assert.h>

#include "../include/SquareEquation.h"
#include "../include/utils.h"

int solve_quadratic_equation (double a, double b, double c, double *x1, double *x2)
{
    if (comp_eps(a, 0))
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

        /*if (comp_eps(*x1, 0))
        {
            *x1 = 0;
        }*/

        if (Debug) printf ("%lg !!!, line = %d\n", *x1, __LINE__);

        return ONE_ROOT;
    }
}

int square_equation (double a, double b, double c, double *x1, double *x2)
{
    assert(x1 != nullptr);
    assert(x2 != nullptr);

    double double_a = 2*a;
    double Discr = b*b - 2*double_a*c;

    if (Debug) printf ("%lg, line = %d\n", Discr, __LINE__);

    if (comp_eps (Discr, 0) || (Discr > 0))
    {
        *x1 = -(b - sqrt(Discr)) / double_a;
        *x2 = -(b + sqrt(Discr)) / double_a;

        if (comp_eps(*x1, 0))
        {
            *x1 = 0;
        }
        if (comp_eps(*x2, 0))
        {
            *x2 = 0;
        }

        if (comp_eps((*x1 - *x2), 0))
        {
            return ONE_ROOT;
        }
        else
        {
            if ((comp_eps (*x1, 0)) || (comp_eps (*x2, 0)))
            {
                return ONE_ROOT;
            }
            else return TWO_ROOTS;
            if (Debug) printf("%lg %lg, line = %d\n", *x1, *x2, __LINE__);
        }
    }
    else
    {
        return ZERO_ROOT;
    }
}
