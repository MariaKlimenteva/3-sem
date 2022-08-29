//=============================================================================
#ifndef INPUT_H
#define INPUT_H

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
const bool Debug = false;
const int Max_str = 256;
//-----------------------------------------------------------------------------
//! @brief The output function is responsible for what appears in the console, reads what the user enters.
//! In the case when there was an incorrect input, the trolling part of the function is enabled
//!
//! @param [in] a, b, c - coefficients defining the quadratic equation ax^2 + bx + c = 0
//!
//! @return What the functions linear_equation and square_equation return, i.e. the number of roots
//-----------------------------------------------------------------------------
int input (double *a, double *b, double *c);
//-----------------------------------------------------------------------------
//! @brief A three-dimensional array is created in which 3 rows are placed.
//! One of the lines is randomly selected and displayed on the screen when the user makes an incorrect input
//!
//! @param missing
//!
//! @return returns nothing
//-----------------------------------------------------------------------------
void trolling ();
//-----------------------------------------------------------------------------
//! @brief Displays another sentence on the screen if the trolling function was called, i.e. an incorrect input was made
//!
//! @param missing
//!
//! @return returns nothing
//-----------------------------------------------------------------------------
void is_trolling();
//-----------------------------------------------------------------------------
//! @brief Reads from the file the three lines that are used in the function trolling
//!
//! @param missing
//!
//! @return returns nothing
//-----------------------------------------------------------------------------
int start_trolling (char ch[][Max_str], const int num_lines);

#endif // INPUT_H
