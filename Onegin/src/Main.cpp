//=============================================================================
//! @brief Sort files by beginning and end of line, output sorted texts and original text
//!
//! @author Klimenteva Maria (https://github.com/MariaKlimenteva/MIPT_Huawei_course/tree/main/Onegin/src)
//! @file Main.cpp
//! @date 18.09.2022
//!
//! @copyright Copyright (c) 2022
//-----------------------------------------------------------------------------

/*
I don’t mean to please grand people.
With love friends’ notions I’d rate
And give you all that 1 could scribble
As pawn that’s worth of dear mate.
Its worth of fine and charming soul,
Of saint fulfilled generous dreams,
Of lively lucid verse’s glow,
Of lofty thoughts, of simple things.
All right, by hand unfair own
You take my set of florid rhymes
Which are half-funny and half-mournful,
Of common thinking, somewhat thoughtful,
Slipshod result of my pastimes,
Of sleepless nights, of inspirations,
Of years young but whithered hard,
Of mind some cold observations,
Of grievous notes of the heart.
CHAPTER ONE
He hurries up to live, As well as he does to feel.
K. Vyasemsky.
*/

#include <stdlib.h>

#include "Strings_Utils.h"
#include "File_Size_Utils.h"
#include "Strings_Comparator.h"
#include "Print_In_File.h"

enum Error_Sensitive_Exit_Codes
{
    SUCCESS        =  0,
    OPEN_FILE_FAIL = -1,
};

int main()
{
 
    int    length_of_file                = count_file_length (fp);
    char*  buffer                        = (char*)  calloc (length_of_file + 1, sizeof(char));

    read_the_file(fp, length_of_file, buffer);

    if (fp)
    {
        printf("File open %s\n", __FILE__);
    }

    else
    {
        perror("The file did not open\n");
        return OPEN_FILE_FAIL;  
    }

    int    num_lines                     = count_lines_in_file (buffer, length_of_file);
    char** lines                         = (char**) calloc (num_lines, sizeof(char*));

    fclose(fp);    
    
    printf ("Number of strings in the file = %d\n", num_lines);
    printf ("Length of the file = %d\n", length_of_file);

    split_by_newline(buffer, length_of_file, lines, num_lines); 

    printf ("'");
    print_in_file (stdin, num_lines, lines);
    printf ("'");

    qsort(lines, num_lines, sizeof(lines[0]), compare_beginnings_of_lines);

    print_in_file(sort_file, num_lines, lines);

    fputc('\n', sort_file);
    fputc('\n', sort_file);

    qsort(lines, num_lines, sizeof(lines[0]), compare_endings_of_lines);

    //printf ("\nasfas\n");

    print_in_file(sort_file, num_lines, lines);

    fclose(sort_file);
    free(buffer);
    free(lines);
    
    return SUCCESS;
}
