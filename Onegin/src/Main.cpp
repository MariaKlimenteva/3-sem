//=============================================================================
//! @brief Sort files by beginning and end of line, output sorted texts and original text
//!
//! @author Klimenteva Maria (https://github.com/MariaKlimenteva/MIPT_Huawei_course/tree/main/Onegin/src)
//! @file Main.cpp
//! @date 18.09.2022
//!
//! @copyright Copyright (c) 2022
//-----------------------------------------------------------------------------

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
    char*  buffer                        = (char*)  calloc (length_of_file, sizeof(char));

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

    // print_in_file (stdin, num_lines, lines);

    qsort(lines, num_lines, sizeof(lines[0]), compare_beginnings_of_lines);
    
    print_in_file(sort_file, num_lines, lines);

    fputc('\n', sort_file);
    fputc('\n', sort_file);

    qsort(lines, num_lines, sizeof(lines[0]), compare_endings_of_lines);

    print_in_file(sort_file, num_lines, lines);

    fclose(sort_file);
    free(buffer);
    free(lines);
    
    return SUCCESS;
}
