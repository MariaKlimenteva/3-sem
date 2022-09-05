
#include "../include/Comp_Åps.h"

int comp_eps (double a, double b)
{
    return fabs (a - b) <= EPS;
}
