
#include "Input.h"

int TROLLING = 0;

int input (double *a, double *b, double *c)
{
    char input_error[2] = "";
    char str[Max_str] = "";

    printf ("To solve the quadratic equation, enter the coefficients:");

    if (Debug) printf (" input, line = %d\n", __LINE__);

    while (true)
    {
        fgets (str, Max_str, stdin);

        int arg_num = sscanf ( str,"%lf %lf %lf %1s", a, b, c, input_error);
        if (Debug) printf ("%d, (%s), line = %d\n", arg_num, input_error, __LINE__);

        if (arg_num == 3)
        {
            if (Debug) printf ("%d, line = %d\n", arg_num, __LINE__);
            break;
        }

        else
        {
            trolling ();
        }

    }

    return 0;
}

void trolling ()
{
    TROLLING = 1;
    const int num_lines = 3;
    char ch[num_lines][Max_str] = {}; // Создаем массив, где будем сохранять считанные из файла

    int random = rand () % (num_lines + 1) + 0;

    start_trolling (ch, num_lines);

    switch (random)
    {
        case 1:
            //printf ("It seems the equation is not exactly square..)");
            printf ("%s\n", ch[0]);
            break;

        case 2:
            //printf ("We don't count triangular equations!!!");
            printf ("%s\n", ch[1]);
            break;

        default:
            //printf ("Incorrect input, enter the coefficients again");
            printf ("%s\n", ch[2]);
            break;

    }
}

int start_trolling (char ch[][Max_str], int num_lines)
{
    FILE *fp = fopen ("Trolling_File.txt", "r"); //"Указатель файла"

    if (!fp)
    {
        printf ("Open file error(\n");
        return 1;
    }

    for (int i = 0; i < num_lines; i++)
    {
        fgets(ch[i], Max_str, fp);
    }

    fclose(fp);

    return 0;
}

void is_trolling()
{
    if (TROLLING == 1)
    {
        printf ("..AND WON'T!!!\n");
    }
}

