#include "Input.h"

// TODO: Read corresponding header file first!

bool trolling = 0;

int input (double *a, double *b, double *c)
{
    bool trolling = false;
    char input_error[2] = "";

    char str[MAX_STR] = "";
// TODO: Why are you using an intermediate buffer instead of reading
//       directly by scanf? Thus limiting line length, cluttering code
//       and adding some unobvious constants like Max_str. For nothing!

    printf ("To solve the quadratic equation, enter the coefficients:");


    while (true)
    {
        fgets (str, MAX_STR, stdin);

        int arg_num = sscanf ( str,"%lf %lf %lf %1s", a, b, c, input_error);

        if (arg_num == 3)
        { // TODO:     ^ You've moved scanf from 3 far enough, 3 has become unobvious
          //           Comment or move them closer together!
            break;
        }
        else // TODO: else after break is considered a bad practice by most style guides
        {
            trolling ();
        }
    }
    return 0; // TODO: Why does this even has a return value if it's always the same?
}

void trolling ()
{
    trolling = true;

    const int NUM_LINES = 3;
    char lines_for_trolling[NUM_LINES][MAX_STR] = {};

    int random = rand () % (NUM_LINES + 1) + 0;
    // TODO:     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Looks like a function get_random(int from, int to)

    start_trolling (lines_for_,trolling, NUM_LINES);

    switch (random)
    {
        case 1:
            printf ("%s\n", lines_for_trolling[0]);
            break;

        case 2:
            printf ("%s\n", lines_for_trolling[1]);
            break;

        case 3:
            printf ("%s\n", lines_for_trolling[2]);
            break;

    }
}

void start_trolling (char lines_for_trolling[][MAX_STR], int NUM_LINES)
{
    FILE *fp = fopen ("Trolling_File.txt", "r");
    //       TODO:    ^~~~~~~~~~~~~~~~~~~ Always the same file?
    //                Document or add ability to switch it for other file and configure in main.

    if (!fp)
    {
        printf ("Open file error(\n");
        // TODO: If fopen failed, there's a way to retrieve an explanation (see perror, strerror and man errno)
        return ONE_ROOT;
    }

    for (int i = 0; i < NUM_LINES; i++) // TODO: Looks like a function, extract!
    {
        fgets(lines_for_trolling[i], MAX_STR, fp);
    }

    fclose(fp);
}

void is_trolling()
{
    if (trolling == true)
    {
        printf ("..AND WON'T!!!\n");
    }
}

