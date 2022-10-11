//=============================================================================
#ifndef STRINGS_COMPARATOR_H
#define STRINGS_COMPARATOR_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_not_alpha_in_str(const char* str, size_t len_str); // TODO: maybe make static in .cpp

//-----------------------------------------------------------------------------
//! @brief 
//!
//! @param [in]
//!
//! @return 
//-----------------------------------------------------------------------------
int compare_beginnings_of_lines(const void* a, const void* b);

//-----------------------------------------------------------------------------
//! @brief
//!
//! @param [in]
//!
//! @return 
//-----------------------------------------------------------------------------
int compare_endings(const void* fst, const void* snd);

#endif // STRINS_COMPARATOR_H