
#ifndef INPUT_H
#define INPUT_H

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const bool Debug = true;
const int Max_str = 256;

int input (double *a, double *b, double *c);

void trolling ();

void is_trolling();

int start_trolling (char ch[][Max_str], const int num_lines);

#endif // INPUT_H
