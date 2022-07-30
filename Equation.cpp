#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double linear_equation(double b, double c, double *x1, double *x2);

int comp_eps(double a, double b);

int input (double *a, double *b, double *c, double *x1, double *x2);
void output (int roots, double *x1, double *x2);

int solve_eq (double a, double b, double c, double *x1, double *x2);

const double EPS = 10e-4;
const int ONE_ROOT = 1;
const int TWO_ROOTS = 2;
const int ZERO_ROOT = -1;
const int INF_ROOT = 3;
const int INPUT_ERROR = 8;
const bool Debug = true;

int main()

{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int roots = 0;
    input (&a, &b, &c, &x1, &x2);
    solve_eq (a, b, c, &x1, &x2);
    return 0;
}

int solve_eq (double a, double b, double c, double *x1, double *x2){

    if (comp_eps(a, 0))
    {
       linear_equation(b, c, x1, x2);
    }
    else
    {
        double Discr = b*b - 4*a*c;


        if (Debug) printf("%lg, line = %d\n", Discr, __LINE__);

        if (Discr >= 0){
            *x1 = -(b - sqrt(Discr))/(2*a);
            *x2 = -(b + sqrt(Discr))/(2*a);
            if (comp_eps((x1 - x2), 0)){
                output(1, x1, x2);
            }
            else {
                output (2, x1, x2);
                if (Debug) printf("%lg %lg, line = %d\n", *x1, *x2, __LINE__);
            }
        }
        else{
                output (-1, x1, x2);
            }

    }
    return 0;
}

double linear_equation (double b, double c, double *x1, double *x2)
{
        if (comp_eps(b, 0))
        {
            if (comp_eps(c, 0))
            {
                printf ("Infinitely many solutions");
            }
            else
            {
                output(0, x1, x2);
            }
        }
        else
        {
           *x1 = -c/b;

           if (Debug) printf("%lg, line = %d\n", *x1, __LINE__);

           output(1, x1, x2);
        }

        return 0;
}

int comp_eps (double a, double b){

    if (abs (a - b) <= EPS) {
        return 1;
    }
    return 0;
}

int input (double *a, double *b, double *c, double *x1, double *x2){

    printf ("To solve the quadratic equation, enter the coefficients:");
    int arg_num = 0;

    if (Debug) printf(" input, line = %d\n", __LINE__);

    arg_num = scanf ("%lf %lf %lf", a, b, c);

    if (Debug) printf(" input, %d, line = %d\n", arg_num, __LINE__);

    if (arg_num != 3){

        if (Debug) printf("%d ..if, line = %d\n", arg_num, __LINE__);

        output(8, x1, x2);
        return 1;
    }
    else return 0;
}

void output (int roots, double *x1, double *x2){
    switch (roots){
        case ONE_ROOT:
            printf ("One solution, x = %lf\n ", x1);
            break;
        case TWO_ROOTS:
            printf ("Two roots: x1 = %d, x2 = %d\n", x1, x2);
            break;
        case INF_ROOT:
            printf ("Infinitely many solutions\n");
            break;
        case ZERO_ROOT:
            printf ("There are no solutions\n");
            break;
        case INPUT_ERROR:
            printf ("There is input error\n");
            break;
        default:
            printf ("Error");
            break;
    }
}









