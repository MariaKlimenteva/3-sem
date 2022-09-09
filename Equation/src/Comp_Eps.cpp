
#include "Comp_Eps.h"

int comp_eps (double a, double b)
{
    return fabs (a - b) <= EPS;
}
