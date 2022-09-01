//=============================================================================
#ifndef INPUT_H
#define INPUT_H

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// ===============================> READ IT AND APPLY! <===============================
// TODO: SEE SquareEquation.h FOR COMMON DOCUMENTATION CRITIQUE THAT APPLIES HERE TOO!

//-----------------------------------------------------------------------------

// TODO: please, chose a common naming style for all constants (I've already
// three different ones: Debug, INFINITE_ROOTS and Max_str). All caps is most
// common (SCREAMING_SNAKE_STYLE), you probably should use it for all constants.
const bool Debug = false;
const int Max_str = 256; // TODO: Very uncommon naming style (everything described above applies)
//-----------------------------------------------------------------------------
//! @brief The output function is responsible for what appears in the console, reads what the user enters.
//! In the case when there was an incorrect input, the trolling part of the function is enabled
//!
//! @param [in] a, b, c - coefficients defining the quadratic equation ax^2 + bx + c = 0
//!
//! @return What the functions linear_equation and square_equation return, i.e. the number of roots
//-----------------------------------------------------------------------------

// TODO: naming, "input" is almost as generic as it gets for such niche
// function, think of a more specific name!
int input (double *a, double *b, double *c);
//-----------------------------------------------------------------------------
//! @brief A three-dimensional array is created in which 3 rows are placed.
//! One of the lines is randomly selected and displayed on the screen when the user makes an incorrect input
//!
//! @param missing
//!
//! @return returns nothing
//-----------------------------------------------------------------------------
void trolling (); // TODO: naming, use imperative (infinitive: to troll, ergo void troll()...)
//-----------------------------------------------------------------------------
//! @brief Displays another sentence on the screen if the trolling function was called, i.e. an incorrect input was made
//!
//! @param missing
//  ^~~~~~~~~~~~~~ TODO: There are no parameters, you don't need this line!
//!
//! @return returns nothing
//  ^~~~~~~~~~~~~~~~~~~~~~~ TODO: Same! Obvious, delete!
//-----------------------------------------------------------------------------
void is_trolling();
//   ^~~ TODO: naming suggests boolean return value (something like is_trolling_enabled),
//             which is misleading!

//-----------------------------------------------------------------------------
//! @brief Reads from the file the three lines that are used in the function trolling
//!
//! @param missing
//  ^~~~~~~~~~~~~~ TODO: Same! Obvious, delete!
//!
//! @return returns nothing
//  ^~~~~~~~~~~~~~~~~~~~~~~ TODO: Same! Obvious, delete!
//-----------------------------------------------------------------------------
int start_trolling (char ch[][Max_str], const int num_lines);
//                       ^~ TODO: naming, I have no idea what ch is

#endif // INPUT_H
