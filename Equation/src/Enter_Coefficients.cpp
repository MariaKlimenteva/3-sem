#include "Square_Equation.h"
#include "Enter_Coefficients.h"

bool trolling = 0;

int enter_coefficients (double *a, double *b, double *c)
{
    bool trolling = false;
    char input_error[2] = "";

    printf ("To solve the quadratic equation, enter the coefficients:");


    while (true)
    {
        if (scanf ("%lf %lf %lf %1s", a, b, c, input_error) != 3)
        { 
            troll (); 
        }
        else 
        {
            break;
        }
    }
}

void troll ()
{
    trolling = true;

    const int NUM_LINES = 3;
    char lines_for_trolling [NUM_LINES][] = {};

    int random = get_random (1, NUM_LINES);

    start_trolling (lines_for_trolling, NUM_LINES);

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

void start_trolling (char lines_for_trolling[][], int NUM_LINES)
{
    FILE *fp = fopen ("Trolling_File.txt", "r");

    if (!fp)
    {
        perror ("Open file error(\n :");
    }

    for (int i = 0; i < NUM_LINES; i++) // TODO: Looks like a function, extract!
    {
        fgets(lines_for_trolling[i], MAX_STR, fp);
    }

    fclose(fp);
}

void continue_troll()
{
    if (trolling)
    { 
        printf ("..AND WON'T!!!\n");
    }
}

int get_random(int from, int to)
{
    int random = from + rand () % to;
    return random;
}
