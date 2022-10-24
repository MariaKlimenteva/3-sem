#include <stdio.h>
#include <.h>

int main()
{
    FILE* fp = fopen("CMD.txt", "r");
    int    length_of_file                = count_file_length (fp);
    char*  buffer                        = (char*)  calloc (length_of_file, sizeof(char));
    char*  codes_arr                     = (char*)  calloc (length_of_file, sizeof(int));

    int cmd_counter = 0;
    int arg_counter = 0;
    read_the_file(fp, length_of_file, buffer);
    division_into_words (buffer, length_of_file);
    int len = fill_in_codes_array (buffer, length_of_file, codes_arr, cmd_counter, arg_counter);
        
    FILE* code_file = fopen("Code.txt", "w");
    print_in_file(code_file, codes_arr, len);

    return 0;
}

