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


int main()
{
    FILE *fp = fopen ("Eugene_Onegin.txt", "r");
    
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
    char* array_store_strings_from_file = (char*) calloc (length_of_file, sizeof(char));
    char** str_ptr = (char**) calloc (num_lines, sizeof(char*));


    printf ("Number of strings in the file = %d\n", num_lines);
    printf ("Length of the file = %d\n", length_of_file);

    read_the_file (fp, length_of_file, array_store_strings_from_file);
    fclose(fp);
    change_whitespace_symbols (array_store_strings_from_file, length_of_file, str_ptr);  

    qsort(str_ptr, num_lines, sizeof(str_ptr[0]), compare); 



    for(int i = 0; i < num_lines; i++)
    {
        printf("%s\n", str_ptr[i]);
    }

    free(array_store_strings_from_file);
    free(str_ptr);
    
    return EXIT_SUCCESS;
}
 
void read_the_file (FILE *fp, int length_of_file, char* array_store_strings_from_file)
{
    fread (array_store_strings_from_file, sizeof(char), length_of_file, fp);    
}

void change_whitespace_symbols (char* array_store_strings_from_file, int length_of_file, char** str_ptr)
{
    int j = 0; 
    str_ptr[0] = array_store_strings_from_file;
    for (int i = 0; i < length_of_file; i++)
    {
        if(array_store_strings_from_file[i] == '\n')
        {
            array_store_strings_from_file[i] = '\0';
            if(i != length_of_file - 1)
            {
                j++;
                str_ptr[j] = array_store_strings_from_file + i + 1;
            } 
            

        }
        array_store_strings_from_file[length_of_file - 1] = '\0';
    }

    printf("\n\n\n\n");
}

int compare(const void* a, const void* b)
{
    char* b1 = (char*)b;
    char* a1 = (char*)a;
    return strcmp(a1, b1);
}