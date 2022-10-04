
#include "Strings_Utils.h"

int read_the_file (FILE *fp, int length_of_file, char* buffer)
{
    int read_elements = fread (buffer, sizeof(char), length_of_file, fp);
    feof(fp);
    return read_elements;    
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

