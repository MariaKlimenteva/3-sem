
#include "File_Size_Utils.h"
#include "Strings_Utils.h"

int count_lines_in_file (char* buffer, int length_of_file)
{
    int count_lines = 0;  

    for (int i = 0; i < length_of_file; i++)
    {
        if(buffer[i] == '\n' || buffer[i] == '\0')
        {
            count_lines++;
        }
    }
    return count_lines;
}

int count_file_length (FILE *fp)
{ // TODO: can you make this without side-effect of rewinding file
    assert (fp);

    fseek (fp, 0, SEEK_END);
    int len = ftell (fp) + 1;
    rewind (fp);    
    
    return len;
}
