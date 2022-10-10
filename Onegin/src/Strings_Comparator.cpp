
#include "Strings_Comparator.h"

int compare_beginnings_of_lines(const void* a, const void* b)
{
    const char* b1 = (const char*)b;
    const char* a1 = (const char*)a;

    printf("Comparing strings:\n%s\n%s\nResult = %d\n", a1, b1, strcmp(a1, b1));
    return strcmp (a1, b1);
}

int compare_endings_of_lines (const void* string_1, const void* string_2)
{
    const char* str_1 = (const char*)string_1;
    const char* str_2 = (const char*)string_2;

    size_t len_str_1 = strlen (str_1); // TODO: very slow! 
    size_t len_str_2 = strlen (str_2);

    size_t num_not_alpha_str_1 = count_not_alpha_in_str (str_1, len_str_1);
    size_t num_not_alpha_str_2 = count_not_alpha_in_str (str_2, len_str_2); // TODO: how many strlens do you want?!

    const char* cur_str_1 = str_1 + len_str_1 - 1 - num_not_alpha_str_1;
    const char* cur_str_2 = str_2 + len_str_2 - 1 - num_not_alpha_str_2;

    len_str_1 -= num_not_alpha_str_1; // TODO: not alnum symbols can be found not only at the end of lines 
    len_str_2 -= num_not_alpha_str_2;

    size_t m = ((len_str_1 <= len_str_2) ? len_str_1 : len_str_2); 
    //     ^ TODO: Why 'm'? You can do better than this! :)

    for(size_t i = 0; i < m; i++)
    {        
        if(*(cur_str_1 - i) - *(cur_str_2 - i) != 0)
        {
            return cur_str_1[-i] - cur_str_2[-i];
            //     ^~~~~~~~~~~~~~~~ TODO: unconventional (e.g. cur_str_1[i])
        }
    }

    return 0;
}

int count_not_alpha_in_str(const char* str, size_t len_str)
{
    int count = 0;
    
    for(size_t i = 0; i < len_str; i++)
    {
        if(!isalpha(*(str + len_str - 1 - i)))
        {
            count++;
        }
        else
        {
            break;
        }
    }

    return count;
}

/*
int compare_endings_of_lines(const void *a, const void *b)
{
    const char* a1 = (const char*) a;
    const char* b1 = (const char*) b;

    size_t len_a1 = strlen (a1);
    size_t len_b1 = strlen (b1);

    const char* cur_str_1 = a1 + len_a1;
    const char* cur_str_2 = b1 + len_b1;

    for(size_t i = len_a1; i > 0;)
    {
        for(size_t j = len_b1; j > 0;)
        {
            if((isalpha(cur_str_1[i])) && (isalpha(cur_str_2[j])))
            {
                if((cur_str_1[i] - cur_str_2[j]) != 0)
                {
                    return cur_str_1[i] - cur_str_2[j];   
                }
                i--;
                j--;
            }
            if(!(isalpha(cur_str_1[i])))
            {
                i--;
            }
            if(!(isalpha(cur_str_2[j])))
            {
                j--;
            }
        }  
    }
    return 0;
}
*/