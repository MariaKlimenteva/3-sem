//=============================================================================
//! @brief 
//!
//! @author Klimenteva Maria (https://github.com/MariaKlimenteva/MIPT_Huawei_course/tree/main/Onegin/src)
//! @file Main.cpp
//! @date 18.09.2022
//!
//! @copyright Copyright (c) 2022
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int count_lines_in_file (FILE *fp);

int main()
{
    FILE *fp = fopen ("../Eugene_Onegin.txt", "r");
    // TODO: Do not trust spaces^ (it works, but kinda scary :)
    printf("File open\n"); // TODO: extract in logging wrapper (that could be disabled in release) later
                           // HINT: use conditional compilation (and macros, meaning defines), also see:
                           //       __LINE__, __FUNCTION__, __FILE__, ...

    if (!fp)
    {
        perror("The file did not open\n");
        return 0; // EXIT_SUCCESS (read about exit codes and EXIT_FAILURE, EXIT_SUCCESS)? O'Rly?
    }
    
    int num_lines = count_lines_in_file(fp);
    // TODO: count all lines, delete unnecessary           ^~
    //       or sort them with everything else
    //       or move them (with your comparator) to the top of resulting file
    //       or skip them during output (debatable)
    //       or do whatever you like with them, just not random "/ 2"
    printf("Number of strings in the file = %d\n", num_lines);
  

    // TODO: avoid VLA (variable-length-array), use alloc family!
    char* array_store_strings_from_file[num_lines];   
    char slash_n [] = {'\n'}; // TODO: Why? Remove! (Or rethink your design!)

    for (int i = 0; i <= num_lines + 1; i++)
    { //               ^ TODO: does count_of_lines + 1 iterations
        printf("Start of scanf file\n");
        fscanf(fp, "%ms", array_store_strings_from_file + i);
        //           ^ TODO: does this work on Windows?
        // I'm not sure, (and this is definitely not part of the standard), beware! 
        // Pay close attention to this, and expect that it may not work.
        
        // TODO: just not printf :)
        printf("%p\n", array_store_strings_from_file[i]);

    }


    // TODO: for your first iteration use qsort (stdlib.h) for sorting!
    return 0;
}
 
int count_lines_in_file (FILE *fp)
{ 
    int count_of_lines = 1;
    char read_symbols_from_file = '\0'; 
    
    while ((read_symbols_from_file = fgetc(fp)) != EOF)
    {
        
        if (read_symbols_from_file == '\n')
        {
            count_of_lines++;
        }
    }
    return count_of_lines;
}

int compare_first_letter_alfabet_order()
{
    // swap(); // TODO: comparator doesn't need to swap anything!
    //         // I mean, it's a comparator it literally just compares!
    return 0;
}