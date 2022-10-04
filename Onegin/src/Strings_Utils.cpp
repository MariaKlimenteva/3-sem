
#include "Strings_Utils.h"

FILE* fp = fopen("Short.txt", "r");

void read_the_file (FILE* fp, int length_of_file, char* buffer)
{
    int read_symbols = fread (buffer, sizeof(char), length_of_file, fp);
    feof(fp);   
    printf("File was read\n");
    printf("The characters were read: %d\n", read_symbols);
}

void split_by_newline (char* buffer, int length_of_file, char** lines)
{
    int j = 0;
    int count_lines = 1;  
    lines[0] = buffer;

    for (int i = 0; i < length_of_file; i++)
    {
        if(buffer[i] == '\n')
        {
            buffer[i] = '\0';
            count_lines += 1;
            
            if(i != length_of_file - 1)
            {
                j++;
                lines[j] = buffer + i + 1;
            } 
        }
    }
    buffer[length_of_file - 1] = '\0';
    printf("%d\n", count_lines);
 //   return count_lines;
}

