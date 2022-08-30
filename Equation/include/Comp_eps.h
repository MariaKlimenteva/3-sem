//=============================================================================
#ifndef COMP_EPS_H
#define COMP_EPS_H

#include <math.h>
//-----------------------------------------------------------------------------
const double EPS = 10e-4;
//-----------------------------------------------------------------------------
//! @brief Checking for the tendency of the difference of numbers to zero
//!
//! @param [in] a, b - Two numbers whose difference is compared with EPS
//!
//! @return 0
//-----------------------------------------------------------------------------
int comp_eps (const double a, const double b);

#endif
