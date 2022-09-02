// TODO: same thing, why include TXlib if you don't ever use it?
// #include <TXlib.h>

// TODO: and same thing here, don't use relative paths to includes (see Main.cpp for more info) 
#include "../include/unit_tests.h"
#include "../include/SquareEquation.h"
#include "../include/Comp_eps.h"

void unit_test (double a, double b, double c, int test_roots, double test_x1, double test_x2)
{                         // TODO:                ^~~~               ^~~~            ^~~~ Test? More like "expected"
    double x1 = 0, x2 = 0;

    int roots = solve_quadratic_equation (a, b, c, &x1, &x2);

    if (((comp_eps (x1, test_x1)) || (comp_eps(x1, test_x2))) && ((comp_eps(x2, test_x1)) || (comp_eps(x2, test_x2))) && (roots == test_roots))
    {
        $sg; printf ("Test passed\n");
    //  ^~~ TODO: Is this the entire reason for including TXLib? Could have implemented it easily yourself.
    //  Would be a better solution, since using TXLib you're giving up support for dozens of platforms,
    //  including Linux (what I use), so I can't run it.

    //  Also, if you're using TXLib, you should at least include it in your repo (as submodule or just text
    //  file, doesn't matter that much).
    }
    else
    {
        $sr; printf ("Test failed\n a = %lf, b = %lf, c = %lf,\n right x1 = %lf\n right x2 = %lf\n x1 = %lf x2 = %lf\n Right roots = %d, roots = %d\n", a, b, c, test_x1, test_x2, x1, x2, test_roots, roots);
    }
}

void unit_Test_fromFile (double a, double b, double c, int test_roots, double test_x1, double test_x2)
{
    FILE *fp = fopen ("text_files/Tests.txt", "r");
    // TODO:           ^~~~~~~~~~ Do tests really belong in generic folder "text_files".
    //                 I mean, programs are text files too... Think of a better name for folder!

    if (!fp)
    {
        // TODO: already commented somewhere, see man errno, so you can give a more detailed error 
        printf("The file did not open\n");
        return;
    }

    while (true)
    {
        int check = (fscanf(fp, "%lf %lf %lf %d %lf %lf", &a, &b, &c, &test_roots, &test_x1, &test_x2));
// TODO:    ^~~~~ Is "check" the best name you could think of? Name suggests boolean type, misleading.
        printf("%d\n", check);
        if (check == EOF)
        { // TODO:   ^~~ Are you sure it's the only thing that could go wrong?
          // (scanf returns number of successful matches), should compare "check" to that.
            break;
        }

        else
        {
            unit_test (a, b, c, test_roots, test_x1, test_x2);
        }
    }
}
