//=============================================================================
#ifndef STRINGS_UTILS_H
#define STRINGS_UTILS_H

#include <stdio.h> 

extern FILE* fp;

//-----------------------------------------------------------------------------
//! @brief Pass through the array, replacing characters '\n' to '\0'.
//!
//! @param [in] buffer - the array where we wrote everything from the file and the lines are separated by '\0'.
//!
//! @param [in] length_of_file - the number of characters in the file in bytes.
//!
//! @param [in] lines - array with pointers to the beginning of lines.
//-----------------------------------------------------------------------------
void split_by_newline(char* buffer, int length_of_file, char** lines, int num_lines);

//-----------------------------------------------------------------------------
//! @brief Read a file into an buffer. fread returns the number of characters read,
//! or another, in case of a reading error or reaching the end of the file.
//!
//! @param [in] fp - file pointer.
//!
//! @param [in] length_of_file - the number of characters in the file in bytes.
//!
//! @param [in] buffer - the array where we wrote everything from the file and the lines are separated by '\0'.
//-----------------------------------------------------------------------------
void read_the_file (FILE *fp, int length_of_file, char* buffer);

#endif // STRINGS_UTILS_H