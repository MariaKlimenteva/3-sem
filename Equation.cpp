#include <TXlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

const double EPS = 10e-4;
const int Max_str = 256;
const int ONE_ROOT = 1;
const int TWO_ROOTS = 2;
const int ZERO_ROOT = -1;
const int INF_ROOTS = 3;
      int TROLLING = 0;

const bool Debug = true;

double linear_equation (double b, double c, double *x1);

int comp_eps (double a, double b);

int input (double *a, double *b, double *c);
void output (int roots, double x1, double x2);


int solve_eq (double a, double b, double c, double *x1, double *x2);

void trolling ();
int start_trolling (char ch[][Max_str], int num_lines);

void unit_test (double a, double b, double c, int test_roots, double test_x1, double test_x2);

int main ()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int roots = 0;

    unit_test (1, 2, 1, 1, -1, 0);

    srand(time(0));
    input (&a, &b, &c);
    roots = solve_eq (a, b, c, &x1, &x2);
    output (roots, x1, x2);

    return 0;
}

int solve_eq (double a, double b, double c, double *x1, double *x2)
{
    if (comp_eps(a, 0))
    {
       linear_equation (b, c, x1);
    }
    else
    {
        double Discr = b*b - 4*a*c;


        if (Debug) printf ("%lg, line = %d\n", Discr, __LINE__);

        if (comp_eps (Discr, 0) || (Discr > 0))
        {
            *x1 = -(b - sqrt(Discr))/(2*a);
            *x2 = -(b + sqrt(Discr))/(2*a);

            if (comp_eps((*x1 - *x2), 0))
            {
                return 1;
            }

            else
            {
                return 2;

                if (Debug) printf("%lg %lg, line = %d\n", *x1, *x2, __LINE__);
            }
        }

        else
        {
            return -1;
        }

    }

    return 0;
}

double linear_equation (double b, double c, double *x1)
{
        if (comp_eps(b, 0))
        {
            if (comp_eps(c, 0))
            {
                printf ("Infinitely many solutions");
            }

            else
            {
                return 0;
            }
        }

        else
        {
           *x1 = -c/b;

           if (Debug) printf ("%lg, line = %d\n", *x1, __LINE__);

           return 1;
        }
    return 0;
}

int comp_eps (double a, double b)
{
    if (fabs (a - b) <= EPS)
    {
        return 1;
    }

    return 0;
}

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

void output (int roots, double x1, double x2)
{
    switch (roots)
    {
        case ONE_ROOT:

            printf ("One solution, x = %lf\n ", x1);
            break;

        case TWO_ROOTS:

            printf ("Two roots: x1 = %lf, x2 = %lf\n", x1, x2);
            break;

        case INF_ROOTS:

            printf ("Infinitely many solutions\n");
            break;

        case ZERO_ROOT:

            printf ("There are no solutions\n");

            if (TROLLING == 1)
            {
                printf ("..AND WON'T!!!\n");
            }

            break;

        default:

            printf ("Error");
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

void unit_test (double a, double b, double c, int test_roots, double test_x1, double test_x2)
{
    double x1 = 0, x2 = 0;

    int roots = solve_eq (a, b, c, &x1, &x2);

    if (test_roots == roots && roots == INF_ROOTS)
    {
        $sg; printf ("Test passed\n");
    }

    if (((comp_eps (x1, test_x1)) || (comp_eps(x1, test_x2))) && ((comp_eps(x2, test_x1)) || (comp_eps(x2, test_x2))))
    {
        $sg; printf ("Test passed\n");
    }
    else
    {
        $sr; printf ("Test failed\n right x1 = %lf\n right x2 = %lf\n x1 = %lf x2 = %lf\n Right roots = %d, roots = %d\n", test_x1, test_x2, x1, x2, test_roots, roots);
    }
}









