
#include <assert.h>

#include "Square_Equation.h"

int solve_quadratic_equation (double a, double b, double c, double *x1, double *x2)
{
    assert (a != NAN); 
    assert (b != NAN);
    assert (c != NAN);
    assert ((x1 != nullptr) || (x2 != nullptr));
    assert ((a != INFINITY) || (b != INFINITY) || (c != INFINITY));
    assert (x1 == x2);


    if (is_zero(a))
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
    assert (x1 != nullptr);
    assert (b != NAN);
    assert (c != NAN);

    if (is_zero(b))
    {
        if (is_zero(c))
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
    assert(x1 != nullptr);
    assert(x2 != nullptr);

    double a_doubled = 2*a;

    double discriminant = b*b - 2*a_doubled*c;

    if (is_zero(discriminant))
    {
        *x1 = -b/a_doubled;
        return ONE_ROOT;
    }

    if (discriminant > 0)
    {
        *x1 = -(b - sqrt(discriminant)) / a_doubled;
        *x2 = -(b + sqrt(discriminant)) / a_doubled;

        if (is_zero(*x1)) 
        {
            destroy_minus_zero(*x1);
        }
        if (is_zero(*x2))
        {
            destroy_minus_zero(*x2);
        }

        if (is_zero(*x1) || is_zero(*x2))
        {
            return ONE_ROOT;
        }
        
        return TWO_ROOTS;
    }

    if (discriminant < 0)
    {
        return ZERO_ROOTS;
    }
}

bool is_zero(double value) 
{
    return comp_eps(value, 0.0) == 0;
}

void destroy_minus_zero(double x)
{
    x = 0;
}