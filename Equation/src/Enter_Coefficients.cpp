#include "Square_Equation.h"
#include "Enter_Coefficients.h"

bool trolling = 0;

void enter_coefficients (double *a, double *b, double *c)
{
    char input_error[2] = "";
    printf ("To solve the quadratic equation, enter the coefficients:");
    
    while (true)
    {
        
        if (scanf("%lf %lf %lf", a, b, c) != 3)
        { 
            troll (); 
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
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

    char* lines_for_trolling [NUM_LINES];

    int random = get_random (1, NUM_LINES);

    start_trolling (lines_for_trolling);

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

void start_trolling (char* lines_for_trolling[NUM_LINES])
{
    FILE *fp = fopen ("files_for_reading/Trolling_File.txt", "r");

    if (!fp)
    {
        perror ("Open file error(\n :");
    }

    for(int i = 0; i < NUM_LINES; i++)
    {
	    fscanf(fp, "%ms", lines_for_trolling + i);
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
