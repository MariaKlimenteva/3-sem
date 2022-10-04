
#include "Strings_Utils.h"

void read_the_file (FILE *fp, int length_of_file, char* buffer)
{
    fread (buffer, sizeof(char), length_of_file, fp);
    feof(fp);   
}

void split_by_newline (char* buffer, int length_of_file, char** lines)
{
    int j = 0;  
    lines[0] = buffer;

    for (int i = 0; i < length_of_file; i++)
    {
        if(buffer[i] == '\n')
        {
            buffer[i] = '\0';
            
            if(i != length_of_file - 1)
            {
                j++;
                lines[j] = buffer + i + 1;
            } 
        }
    }
    buffer[length_of_file - 1] = '\0';
}

