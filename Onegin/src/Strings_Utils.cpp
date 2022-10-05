
#include "Strings_Utils.h"

FILE* fp = fopen("Short.txt", "r");

void read_the_file (FILE* fp, int length_of_file, char* buffer)
{
    int read_symbols = fread (buffer, sizeof(char), length_of_file, fp);
    feof(fp);   
    printf("File was read\n");
    printf("The characters were read: %d\n", read_symbols);
}

void split_by_newline (char* buffer, int length_of_file, char** lines, int num_lines)
{
    lines[0] = buffer;
    
    int curPos = 1;

    for (int i = 0; i < length_of_file; i++)
    {
        if(buffer[i] == '\n')
        {
            buffer[i] = '\0';
            
            lines[curPos++] = buffer + i + 1;

            printf ("%s\n", lines[curPos - 1]);
        }

        // printf ("%d %d %d\n", i, num_lines, curPos);
    }

    buffer[length_of_file] = '\0';
}

