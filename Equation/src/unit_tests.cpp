
#include <TXlib.h>

#include "unit_tests.h"
#include "../SquareEquation/SquareEquation.h"
#include "../Comp_eps/Comp_eps.h"

void unit_test (double a, double b, double c, int test_roots, double test_x1, double test_x2)
{
    double x1 = 0, x2 = 0;

    int roots = solve_quadratic_equation (a, b, c, &x1, &x2);

    if (((comp_eps (x1, test_x1)) || (comp_eps(x1, test_x2))) && ((comp_eps(x2, test_x1)) || (comp_eps(x2, test_x2))) && (roots == test_roots))
    {
        $sg; printf ("Test passed\n");
    }
    else
    {
        $sr; printf ("Test failed\n a = %lf, b = %lf, c = %lf,\n right x1 = %lf\n right x2 = %lf\n x1 = %lf x2 = %lf\n Right roots = %d, roots = %d\n", a, b, c, test_x1, test_x2, x1, x2, test_roots, roots);
    }
}

void unit_Test_fromFile (double a, double b, double c, int test_roots, double test_x1, double test_x2)
{
    FILE *fp = fopen ("Tests.txt", "r");

    if (!fp)
    {
        printf("The file did not open\n");
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
