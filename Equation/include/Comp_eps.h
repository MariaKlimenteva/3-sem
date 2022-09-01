//=============================================================================
#ifndef COMP_EPS_H
#define COMP_EPS_H

#include <math.h>
//-----------------------------------------------------------------------------
// TODO: Isn't this an implementation detail?
const double EPS = 10e-4;
//-----------------------------------------------------------------------------
//! @brief Checking for the tendency of the difference of numbers to zero
//  TODO:  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//         Paraphrase, bad wording makes it very hard to understand what you meant.  
//!
//! @param [in] a, b - Two numbers whose difference is compared with EPS
//!
//! @return 0 TODO: Really?
//-----------------------------------------------------------------------------
int comp_eps (const double a, const double b);

#endif
