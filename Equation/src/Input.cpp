#include "../include/Input.h"

// TODO: Read corresponding header file first!

// TODO: Global state! Replace global variable with a local one!
int TROLLING = 0; // TODO: now it's not constant, but you name it in all-caps...
// TODO: If this is actually a boolean value, use "bool" type instead of int!

int input (double *a, double *b, double *c)
{
    char input_error[2] = "";

    char str[Max_str] = "";
// TODO: Why are you using an intermediate buffer instead of reading
//       directly by scanf? Thus limiting line length, cluttering code
//       and adding some unobvious constants like Max_str. For nothing!

    printf ("To solve the quadratic equation, enter the coefficients:");

    if (Debug) printf (" input, line = %d\n", __LINE__);
//  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TODO: Why isn't this a macro?

    while (true)
    {
        fgets (str, Max_str, stdin);

        int arg_num = sscanf ( str,"%lf %lf %lf %1s", a, b, c, input_error);
        if (Debug) printf ("%d, (%s), line = %d\n", arg_num, input_error, __LINE__);
// TODO: ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//       Same thing here, extract!

        if (arg_num == 3)
        { // TODO:     ^ You've moved scanf from 3 far enough, 3 has become unobvious
          //           Comment or move them closer together!
            if (Debug) printf ("%d, line = %d\n", arg_num, __LINE__);
            // TODO: ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ You get the idea!
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
    TROLLING = 1;
    // TODO:   ^ use "true" or "false" for boolean values 

    const int num_lines = 3;
    char ch[num_lines][Max_str] = {};
// TODO: ^~ What is "ch"? Think of a better name!

    int random = rand () % (num_lines + 1) + 0;
    // TODO:     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Looks like a function get_random(int from, int to)

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
            // TODO: assert? See main.cpp for details.  

            //printf ("Incorrect input, enter the coefficients again");
            printf ("%s\n", ch[2]);
            break;

    }
}

int start_trolling (char ch[][Max_str], int num_lines)
{
    FILE *fp = fopen ("Trolling_File.txt", "r");
    //       TODO:    ^~~~~~~~~~~~~~~~~~~ Always the same file?
    //                Document or add ability to switch it for other file and configure in main.

    if (!fp)
    {
        printf ("Open file error(\n");
        // TODO: If fopen failed, there's a way to retrieve an explanation (see perror, strerror and man errno)
        return 1; // Use enum to express error codes 
    }

    for (int i = 0; i < num_lines; i++) // TODO: Looks like a function, extract!
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

