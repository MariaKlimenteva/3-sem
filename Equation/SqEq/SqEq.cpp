
#include "SqEq.h"

int solve_eq (double a, double b, double c, double *x1, double *x2)
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
    if (comp_eps(b, 0))
    {
        if (comp_eps(c, 0))
        {
            return 3;
        }
        else
        {
            /*printf ("b = 0");*/
            return -1;
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

        /*printf ("One root, return 1\n");*/
        return 1;
    }
}

int square_equation (double a, double b, double c, double *x1, double *x2)
{
    double Discr = b*b - 4*a*c;

    if (Debug) printf ("%lg, line = %d\n", Discr, __LINE__);

    if (comp_eps (Discr, 0) || (Discr > 0))
    {
        *x1 = -(b - sqrt(Discr))/(2*a);
        *x2 = -(b + sqrt(Discr))/(2*a);

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
            return 1;
        }
        else
        {
            if ((comp_eps (*x1, 0)) || (comp_eps (*x2, 0)))
            {
                return 1;
            }
            else return 2;
            if (Debug) printf("%lg %lg, line = %d\n", *x1, *x2, __LINE__);
        }
    }
    else
    {
        return -1;
    }
}

