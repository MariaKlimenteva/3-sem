
#include "Unit_Tests.h"
#include "Square_Equation.h"
#include "Comp_Eps.h"

void unit_test (double a, double b, double c, int expected_roots, double expected_x1, double expected_x2)
{
    double x1 = 0, x2 = 0;

    int roots = solve_quadratic_equation (a, b, c, &x1, &x2);

    if (((comp_eps (x1, expected_x1)) || (comp_eps(x1, expected_x2))) && ((comp_eps(x2, expected_x1)) 
    || (comp_eps(x2, expected_x2))) && (roots == expected_roots))
    {
        printf ("Test passed\n");
    }
    else
    {
        printf ("Test failed\n a = %lf, b = %lf, c = %lf,\n right x1 = %lf\n right x2 = %lf\n x1 = %lf x2 = %lf\n Right roots = %d, roots = %d\n",
        a, b, c, expected_x1, expected_x2, x1, x2, expected_roots, roots);
    }
}

void unit_test_from_file (double a, double b, double c, int expected_roots, double expected_x1, double expected_x2)
{
    FILE *fp = fopen ("files_for_reading/Tests.txt", "r");

    if (!fp)
    {
        perror("The file did not open\n");
        return;
    }

    while (true)
    {
        int symbols_from_file = (fscanf(fp, "%lf %lf %lf %d %lf %lf", &a, &b, &c, &expected_roots, &expected_x1, &expected_x2));

        if (symbols_from_file == EOF)
        {
            break;
        }

        else
        {
            unit_test (a, b, c, expected_roots, expected_x1, expected_x2);
        }
    }
}
