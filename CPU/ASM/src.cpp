#include <stdio.h>
#include <Utils.h>

#define VERSION 1

void read_the_file (FILE* fp, int length_of_file, char* buffer)
{
    int read_symbols = fread (buffer, sizeof(char), length_of_file, fp);
    feof(fp);   
    printf("File was read\n");
    printf("The characters were read: %d\n", read_symbols);
}

int count_file_length (FILE *fp)
{ 
    assert (fp);

    fseek (fp, 0, SEEK_END);
    int len = ftell (fp) + 1;
    rewind (fp);    
    
    return len;
}

void division_into_words (char* buffer, int length_of_file)
{
 //   int cmd_counter = 1;
//    int arg_counter = 1;
    for(int i = 0; i < length_of_file; i++)
    {
        if(buffer[i] == '\n')
        {
            buffer[i] = '\0';
 //           cmd_counter++;
        }
        if(buffer[i] == ' ')
        {
            buffer[i] = '\0';
 //           arg_counter++;
        }
    }
    buffer[length_of_file] = '\0';
}

int fill_in_codes_array (char* buffer, int length_of_file, char* codes_arr, int cmd_counter, int arg_counter) // |c|1| |1|\0|1|0|\0|...|\0|
{
    codes_arr[0] = 'c';
    codes_arr[1] = VERSION;


    for(int i = 0; i < length_of_file; i++)
    {
        for(int ip = 3; ip < length_of_file; ip++)
        {
            if(isalpha(buffer[i]))
            {
                if(strcmp(*(buffer[i]), "push") == 0)
                {
                    codes_arr[ip++] = CMD_PUSH;
                }
                if(strcmp(*(buffer[i]), "add") == 0)
                {
                    codes_arr[ip++] = CMD_ADD;
                }
                if(strcmp(*(buffer[i]), "sub") == 0)
                {
                    codes_arr[ip++] = CMD_SUB;
                }
                if(strcmp(*(buffer[i]), "mul") == 0)
                {
                    codes_arr[ip++] = CMD_MUL;
                }
                if(strcmp(*(buffer[i]), "div") == 0)
                {
                    codes_arr[ip++] = CMD_DIV;
                }
                if(strcmp(*(buffer[i]), "out") == 0)
                {
                    codes_arr[ip++] = CMD_OUT;
                }
                if(strcmp(*(buffer[i]), "hlt") == 0)
                {
                    codes_arr[ip++] = CMD_HLT;
                }
                cmd_couner++;
            }
            else
            {
                while(buffer[i] != '\0')
                {
                    codes_arr[ip++] = buffer[i];
                    arg_counter++;
                }
                buffer[i+1] = '\n';
            }
        }
    }
    codes_arr[3] = cmd_counter + arg_counter;
    int len_code_arr = cmd_counter + arg_counter + 3;
    return len_code_arr;
} |c|1|13|1|\0|10|\n|1|\0|20|\n|...|

void print_in_file(FILE* code_file, char* codes_arr, int len) 
{ 
    for(int i = 0; i < len; i++)
    {
        fputs (codes_arr[i], code_file);
    }
}

void compile()
{
    
}
