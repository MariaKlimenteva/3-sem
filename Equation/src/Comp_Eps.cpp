
#include "../include/Comp_Åps.h"

// TODO: Just noticed that file naming is very inconsistent as well.
//       unit_test.cpp, Comp_eps.cpp, SquareEquation.cpp

//       Chose one style and use it consistently. THIS APPLIES EVERYWHERE!

int comp_eps (double a, double b)
{
    return fabs (a - b) <= EPS;
}
