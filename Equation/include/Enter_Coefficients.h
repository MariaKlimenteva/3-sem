//=============================================================================
#ifndef ENTER_COEFFICIENTS_H
#define ENTER_COEFFICIENTS_H

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//-----------------------------------------------------------------------------

const bool DEBUG = false;
const int NUM_LINES = 3;

//-----------------------------------------------------------------------------
//! @brief Is responsible for what appears in the console, reads what the user enters.
//! In the case when there was an incorrect input, the trolling part of the function is enabled
//!
//! @param [in] a, b, c - coefficients defining the quadratic equation ax^2 + bx + c = 0
//!
//! @return What the functions linear_equation and square_equation return, i.e. the number of roots
//-----------------------------------------------------------------------------
void enter_coefficients (double *a, double *b, double *c);

//-----------------------------------------------------------------------------
//! @brief A three-dimensional array is created in which 3 rows are placed.
//! One of the lines is randomly selected and displayed on the screen when the user makes an incorrect input
//-----------------------------------------------------------------------------
void troll (); 

//-----------------------------------------------------------------------------
//! @brief Displays another sentence on the screen if the trolling function was called, i.e. an incorrect input was made
//-----------------------------------------------------------------------------
void continue_troll ();

//-----------------------------------------------------------------------------
//! @brief Reads from the file "Trolling_File.txt", which is located in the folder files_for_reading, the three lines that are used in the function trolling
//!
//! @param [in] lines_for_trolling -  
//!
//! @param [in] NUM_LINES - 
//-----------------------------------------------------------------------------
void start_trolling (char* lines_for_trolling[NUM_LINES]);

//-----------------------------------------------------------------------------
//! @brief 
//!
//! @param [in] from  
//!
//! @param [in] to 
//-----------------------------------------------------------------------------
int get_random(int from, int to);

#endif // ENTER_COEFFICIENTS_H
