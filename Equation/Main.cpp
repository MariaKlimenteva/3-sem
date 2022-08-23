
#include <TXlib.h>

#include "SqEq.h"

enum Number_of_root
{
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    ZERO_ROOT = -1,
    INF_ROOTS = 3
};

void output (int roots, double x1, double x2);
void unit_test (double a, double b, double c, int test_roots, double test_x1, double test_x2);
void unit_Test_fromFile (double a, double b, double c, int test_roots, double test_x1, double test_x2);

int main ()
{
    srand(time(0));

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int roots = 0;

    int test_roots = 0;
    double test_x1 = 0, test_x2 = 0;

    unit_Test_fromFile (a, b, c, test_roots, test_x1, test_x2);

    input (&a, &b, &c);
    roots = solve_eq (a, b, c, &x1, &x2);
    output (roots, x1, x2);

    return 0;
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

            is_trolling();

            break;

        default:

            printf ("Error");
            break;
    }
}

void unit_test (double a, double b, double c, int test_roots, double test_x1, double test_x2)
{
    double x1 = 0, x2 = 0;

    int roots = solve_eq (a, b, c, &x1, &x2);

    if (test_roots == roots && roots == INF_ROOTS)
        $sg; printf ("Test passed\n");

    if (((comp_eps (x1, test_x1)) || (comp_eps(x1, test_x2))) && ((comp_eps(x2, test_x1)) || (comp_eps(x2, test_x2))))
    {
        $sg; printf ("Test passed\n");
    }
    else
        $sr; printf ("Test failed\n right x1 = %lf\n right x2 = %lf\n x1 = %lf x2 = %lf\n Right roots = %d, roots = %d\n", test_x1, test_x2, x1, x2, test_roots, roots);
}

void unit_Test_fromFile (double a, double b, double c, int test_roots, double test_x1, double test_x2)
{
    FILE *fp = fopen ("Tests.txt", "r");//Открываем файл с тестами, где все записано в формате a, b, c, roots, x1, x2

    if (!fp)
    {
        printf("Файл не открылся\n");
        return;
    }

    while (true)
    {
        int check = (fscanf(fp, "%lf %lf %lf %d %lf %lf", &a, &b, &c, &test_roots, &test_x1, &test_x2));
        printf("%d\n", check);
        if (check == EOF)
        {
            break;
        }

        else
        {
            unit_test (a, b, c, test_roots, test_x1, test_x2);
        }
    }
}

