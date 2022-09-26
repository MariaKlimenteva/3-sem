//=============================================================================
//! @brief 
//!
//! @author Klimenteva Maria (https://github.com/MariaKlimenteva/MIPT_Huawei_course/tree/main/Onegin/src)
//! @file Main.cpp
//! @date 18.09.2022
//!
//! @copyright Copyright (c) 2022
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <string.h>

#include "Calculate.h"

void change_whitespace_symbols (char* array_store_strings_from_file, int length_of_file, char** str_ptr);
int compare(const void* a, const void* b);
void read_the_file (FILE *fp, int length_of_file, char* array_store_strings_from_file);
void change_whitespace_symbols (char* array_store_strings_from_file, int length_of_file, char** str_ptr);


int main()
{
    FILE *fp = fopen ("../Eugene_Onegin.txt", "r+");
    
    printf("File open\n"); // TODO: extract in logging wrapper (that could be disabled in release) later
                           // HINT: use conditional compilation (and macros, meaning defines), also see:
                           //       __LINE__, __FUNCTION__, __FILE__, ...

    if (!fp)
    {
        perror("The file did not open\n");
        return EXIT_FAILURE; 
    }
    
    int num_lines = count_lines_in_file (fp);
    int length_of_file = count_file_length (fp);
    char* array_store_strings_from_file = (char*) malloc (sizeof(char) * length_of_file);
    char** str_ptr = (char**) malloc (sizeof(char) * num_lines);

    printf ("Number of strings in the file = %d\n", num_lines);
    printf ("Length of the file = %d\n", length_of_file);

    read_the_file (fp, length_of_file, array_store_strings_from_file);
    fclose(fp);
    change_whitespace_symbols (array_store_strings_from_file, length_of_file, str_ptr);  
    qsort(str_ptr, num_lines, sizeof(str_ptr[0]), &compare); 
    
    return EXIT_SUCCESS;
}

void read_the_file (FILE *fp, int length_of_file, char* array_store_strings_from_file)
{
    fread (array_store_strings_from_file, sizeof(char), length_of_file, fp);    
}

void change_whitespace_symbols (char* array_store_strings_from_file, int length_of_file, char** str_ptr)
{
    for (int i = 0; i < length_of_file; i++)
    {
        if(memchr(array_store_strings_from_file, '\n', length_of_file) != NULL)
        {
            array_store_strings_from_file[i] = '\0';

            for (int j = 0; j < i; j++)
            {
                str_ptr[j] = &array_store_strings_from_file[i + 1]; 
            }  
        }
    }
}

int compare(const void* a, const void* b)
{
    /*for (int j = 0; j < num_lines; j++)
    {
        if (*str_ptr[j] < *str_ptr[j+1])
        {
            str_ptr[j] = str_ptr[j+1];
            str_ptr[j+1] = str_ptr[j];
        }

    }*/

    return *(const int*) a - *(const int*) b;
}