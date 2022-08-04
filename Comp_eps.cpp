
#include "Comp_eps.h"

int comp_eps (double a, double b)
{
    if (fabs (a - b) <= EPS)
    {
        return 1;
    }

    return 0;
}
