#ifndef SQ_EQ_H
#define SQ_EQ_H

#include <stdio.h>
#include <math.h>

#include "../Input/Input.h"
#include "../Comp_eps/Comp_eps.h"

int solve_eq (double a, double b, double c, double *x1, double *x2);

double linear_equation (double b, double c, double *x1);

int square_equation (double a, double b, double c, double *x1, double *x2);

#endif // SQ_EQ_H
