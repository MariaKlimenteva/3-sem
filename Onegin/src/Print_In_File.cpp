
#include "Print_In_File.h"

void print_in_file(FILE* sort_file, int num_lines, char** lines) 
{ 
    for(int i = 0; i < num_lines; i++)
    {
        fputs (lines[i], sort_file);
        fputc ('\n', sort_file);
    }
}