
#include "File_Size_Utils.h"
#include "Strings_Utils.h"

int count_lines_in_file (char* buffer, int length_of_file)
{
    int count_lines = 1;  

    for (int i = 0; i < length_of_file; i++)
    {
        if(buffer[i] == '\n')
        {
            count_lines ++;
        }
    }
    return count_lines;
}

int count_file_length (FILE *fp)
{ // TODO: can you make this without side-effect of rewinding file
    assert (fp);

    fseek (fp, 0, SEEK_END);
    int len = ftell (fp);
    rewind (fp);    
    
    return len;
}

/*int count_lines_in_file (FILE *fp) // TODO: do not read file twice
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
}*/

/*int count_lines_in_file(int length_of_file, char* buffer)
{
    int count_lines = 1;
    for(int i = 0; i < length_of_file - 1; i++)
    {
        if(buffer[i] == '\n')
        {
            count_lines++;
            printf("fjbnbjbnfjnc");
        }
    }
    printf("%d\n", count_lines);
    return count_lines;
}*/