//=============================================================================
#ifndef FILE_SIZE_UTILS_H
#define FILE_SIZE_UTILS_H

#include <stdio.h>
#include <assert.h>

#include "Strings_Utils.h"

//-----------------------------------------------------------------------------
//! @brief
//!
//! @param [in]
//!
//! @return 
//-----------------------------------------------------------------------------
int count_lines_in_file(int length_of_file, char* buffer);

//-----------------------------------------------------------------------------
//! @brief
//!
//! @param [in]
//!
//! @return 
//-----------------------------------------------------------------------------
int count_file_length (FILE *fp);

#endif // FILE_SIZE_UTILS_H