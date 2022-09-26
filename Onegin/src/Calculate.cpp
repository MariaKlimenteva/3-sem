
#include "Calculate.h"

int count_lines_in_file (FILE *fp)
{   
    assert (fp);
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

int count_file_length (FILE *fp)
{
    assert (fp);

    fseek (fp, 0, SEEK_END);
    int len = ftell (fp);
    
    return len;
}