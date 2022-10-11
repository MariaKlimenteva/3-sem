
#include "Strings_Comparator.h"

int compare_beginnings_of_lines(const void* a, const void* b)
{
    const char* b1 = *(const char* const*)b;
    const char* a1 = *(const char* const*)a;

    return strcmp (a1, b1);
}



 /*int compare_endings(const void* fst, const void* snd) {
     const char* fst_str = *(const char* const*) fst;
     const char* snd_str = *(const char* const*) snd;

     size_t fst_len = strlen(fst_str), snd_len = strlen(snd_str);
     const char* fst_end_str = fst_str + fst_len - 1;
     const char* snd_end_str = snd_str + snd_len - 1;

     int min_len = fst_len < snd_len ? fst_len : snd_len; 
     for (int i = 0; i + min_len > 0; -- i) {
         int compared_symbols = fst_end_str[i] - snd_end_str[i];
         if (compared_symbols != 0)
             return compared_symbols;
     }

     return fst_len - snd_len;
 }*/








int compare_endings(const void* fst, const void* snd)
{
    const char* fst_str = *(const char* const*) fst;
    const char* snd_str = *(const char* const*) snd;

    size_t fst_len = strlen(fst_str);
    size_t snd_len = strlen(snd_str);

    const char* end_fst = fst_str + fst_len - 1;
    const char* end_snd = snd_str + snd_len - 1;

    int min = fst_len > snd_len ? snd_len : fst_len;
    for(int i = 0; i + min > 0; --i)
    {
        if(*(end_fst) != *(end_snd))
        {
            return (*(end_fst) - *(end_snd));
        }
        return (fst_len - snd_len);
    }
}