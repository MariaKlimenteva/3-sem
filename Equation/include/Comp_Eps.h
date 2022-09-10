//=============================================================================
#ifndef COMP_EPS_H
#define COMP_EPS_H

#include <math.h>
//-----------------------------------------------------------------------------
const double EPS = 10e-4;
//-----------------------------------------------------------------------------
//! @brief Checking for the tendency of the difference of numbers to zero
//!
//! @param [in] a - one of the double numbers we are comparing
//! @param [in] b - the number with which we compare a
//!
//! @return 0
//-----------------------------------------------------------------------------
int comp_eps (const double a, const double b);

#endif //COMP_EPS