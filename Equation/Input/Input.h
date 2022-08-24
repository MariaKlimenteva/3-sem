
#ifndef INPUT_H
#define INPUT_H

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const bool Debug = true;
const int Max_str = 256;

int input (const double *a, const double *b, const double *c);
void trolling ();
void is_trolling();
int start_trolling (const char ch[][Max_str], const int num_lines);

#endif
