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
#include <ctype.h>
#include "Calculate.h"

void change_whitespace_symbols(char* array_store_strings_from_file, int length_of_file, char** str_ptr);
int compare_beginning_of_lines(const void* a, const void* b);
void read_the_file(FILE *fp, int length_of_file, char* array_store_strings_from_file);



enum ExitCodes
{
    SUCCESS        =  0,
    OPEN_FILE_FAIL = -1,
};

int main()
{
    FILE *fp = fopen("Eugene_Onegin.txt", "r");
    
    printf("File open\n"); // TODO: extract in logging wrapper (that could be disabled in release) later
                           // HINT: use conditional compilation (and macros, meaning defines), also see:
                           //       __LINE__, __FUNCTION__, __FILE__, ...

    if (!fp)
    {
        perror("The file did not open\n");
        return OPEN_FILE_FAIL;  // TODO: make enum with EXIT_CODES
    }

    // TODO: проходиться по буфферу в оперативной памяти.

    int    num_lines                     = count_lines_in_file (fp);
    int    length_of_file                = count_file_length (fp);
    char*  array_store_strings_from_file = (char*) calloc(length_of_file, sizeof(char));
    char** str_ptr                       = (char**) calloc (num_lines, sizeof(char*));

    printf("Number of strings in the file = %d\n", num_lines);
    printf("Length of the file = %d\n", length_of_file);

    read_the_file(fp, length_of_file, array_store_strings_from_file);
    fclose(fp);
    change_whitespace_symbols(array_store_strings_from_file, length_of_file, str_ptr);  

    qsort(str_ptr, num_lines, sizeof(str_ptr[0]), compare_beginning_of_lines);

    FILE *sort_file = fopen("Sort_Onegin.txt", "w");

    for(int i = 0; i < num_lines; i++)
    {
        // printf("%s\n", str_ptr[i]);
        fputs (str_ptr[i], sort_file);
        fputc ('\n', sort_file);
    }
    //сортировка по концу строк
  //  qsort(str_ptr[num_lines], 0, sizeof(str_ptr[0]), compare_ending_of_lines);
    
    for(int i = 0; i < num_lines; i++)
    {
        // printf("%s\n", str_ptr[i]);
        fputs (str_ptr[i], sort_file);
        fputc ('\n', sort_file);
    }

    fclose(sort_file);
    free(array_store_strings_from_file);
    free(str_ptr);
    
    return SUCCESS;
}
 
void read_the_file (FILE *fp, int length_of_file, char* array_store_strings_from_file)
{
    // TODO: check return value
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
}

int compare_beginning_of_lines(const void* a, const void* b)
{
    char** b1 = (char**)b;
    char** a1 = (char**)a;
    return strcmp(*a1, *b1);
}

// TODO: implement your own comparator. use isalpha()
int compare_ending_of_lines(const void *a, const void *b)
{
    char* a1 = *((char**) a);
    char* b1 = * ((char**) b);

    for(int i = 0; i < strlen(a1);)
    {
        for(int j = 0; j < strlen(b1);)
        {
            if((isalpha((int)a1 + strlen(a1) - i)) && (isalpha((int)(b1 + strlen(b1) - j))))
            {
                if(*(a1 + strlen(a1) - i) - *(b1 + strlen(b1) - j) != 0)
                return *(a1 + strlen(a1) - i) - *(b1 + strlen(b1) - j)
            }
            if(!(isalpha((int)a1 + strlen(a1) - i)))
            {
                i++;
            }
            if(!(isalpha((int)b1 + strlen(b1) - j)))
            {
                j++;
            }
        }
    }
//разделить по файлам


