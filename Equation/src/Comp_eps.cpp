
#include "../include/Comp_eps.h"

int comp_eps (double a, double b)
{
    return fabs (a - b) <= EPS;
}
