
#include "../include/Comp_�ps.h"

int comp_eps (double a, double b)
{
    return fabs (a - b) <= EPS;
}
