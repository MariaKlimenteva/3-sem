
#include "SqEq.h"

int solve_eq (double a, double b, double c, double *x1, double *x2)
{
    if (comp_eps(a, 0))
    {
       linear_equation (b, c, x1);
    }
    else
    {
        square_equation (a, b, c, x1, x2);
    }
    return 0;
}

double linear_equation (double b, double c, double *x1)
{
    if (comp_eps(b, 0))
    {
        if (comp_eps(c, 0))
        {
            printf ("Infinitely many solutions");
        }
        else
        {
            return 0;
        }
    }

    else
    {
        *x1 = -c/b;

        if (Debug) printf ("%lg, line = %d\n", *x1, __LINE__);

        return 1;
    }
    return 0;
}

int square_equation (double a, double b, double c, double *x1, double *x2)
{
    double Discr = b*b - 4*a*c;

    if (Debug) printf ("%lg, line = %d\n", Discr, __LINE__);

    *x1 = -(b - sqrt(Discr))/(2*a);
    *x2 = -(b + sqrt(Discr))/(2*a);
    if (comp_eps (Discr, 0) || (Discr > 0))
        {
            if (comp_eps((*x1 - *x2), 0))
            {
                return 1;
            }
            else
            {
                return 2;
                if (Debug) printf("%lg %lg, line = %d\n", *x1, *x2, __LINE__);
            }
        }
        else
        {
            return -1;
        }
}

