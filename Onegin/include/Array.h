//=============================================================================
#ifndef ARRAY_H
#define ARRAY_H

#include <string.h>
#include <stdio.h>

//-----------------------------------------------------------------------------
//! @brief Pass through the array, replacing characters '\n' to '\0'.
//!
//! @param [in] array_store_from_file - the array where we wrote everything from the file and the lines are separated by '\0'.
//!
//! @param [in] length_of_file - the number of characters in the file in bytes.
//!
//! @param [in] str_ptr - array with pointers to the beginning of lines.
//-----------------------------------------------------------------------------
void change_whitespace_symbols(char* array_store_strings_from_file, int length_of_file, char** str_ptr);

//-----------------------------------------------------------------------------
//! @brief Read a file into an array_store_strings_from_file. fread returns the number of characters read,
//! or another, in case of a reading error or reaching the end of the file.
//!
//! @param [in] fp - file pointer.
//!
//! @param [in] length_of_file - the number of characters in the file in bytes.
//!
//! @param [in] array_store_strings_from_file - the array where we wrote everything from the file and the lines are separated by '\0'.
//-----------------------------------------------------------------------------
void read_the_file(FILE *fp, int length_of_file, char* array_store_strings_from_file);

#endif // ARRAY_H