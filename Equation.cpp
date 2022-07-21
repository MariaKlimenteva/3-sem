#include <stdio.h>
#include <stdlib.h>

double a, b, c, x;
double linear_equation(double b, double c);
#define ERROR 10^-4
int comp_error(double a, double b);
int main()
{
    printf ("To solve the quadratic equation, enter the coefficients:");
    scanf ("%lf %lf %lf",&a, &b, &c);


    if (a = 0)
    {
       linear_equation(b, c);
    }
    else
    {
 //       Подсчет дискриминанта
    }
/*    switch (errors){
    case -1:
        printf ("Infinitely many solutions");
        break;
    case 0:
        printf("");
        break;
    case 1:
        printf("");
        break;
    case 2:
        printf("");
        break;

    default:
        printf("");*/
    }

    return 0;
}

//int Discr (double a, b, c)
//return ;


double linear_equation (double b, double c)
{
        if (comp_error(b, 0))
        {
            if (comp_error(c, 0))
            {
                printf ("Infinitely many solutions");
                return -1;
            }
            else
            {
                printf ("There are no solutions");
                return 2;
            }
        }
        else
        {
           x = -c/b;
           printf ("One solution, x = ", x);
           return 1;
        }
}

int comp_error(double a, double b){
    if (abs(a - b) <= ERROR) {
        return 0;
    }
}









