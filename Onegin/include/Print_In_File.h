//=============================================================================
#ifndef PRINT_IN_FILE_H
#define PRINT_IN_FILE_H

#include <stdio.h>

FILE *sort_file = fopen("Sort_Onegin.txt", "w");

//-----------------------------------------------------------------------------
//! @brief
//!
//! @param [in]
//!
//! @return 
//-----------------------------------------------------------------------------
void print_in_file(FILE* sort_file, int num_lines, char** lines);

#endif // PRINT_IN_FILE_H