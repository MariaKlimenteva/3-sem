
#include "Array.h"

FILE *fp = fopen("Eugene_Onegin.txt", "r");

void read_the_file (FILE *fp, int length_of_file, char* array_store_strings_from_file)
{
    fread (array_store_strings_from_file, sizeof(char), length_of_file, fp);
    feof(fp);    
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
}

