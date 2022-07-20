#include <stdio.h>
#include <stdlib.h>

double a, b, c, x;
double linear_equation(double b, double c);
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

    return 0;
}

//int Discr (double a, b, c)
//return ;


double linear_equation (double b, double c)
{
        if (b = 0)
        {
            if (c = 0)
            {
                printf ("Infinitely many solutions");
                return (-1);
            }
            else
            {
                printf ("There are no solutions");
                return (2);
            }
        }
        else
        {
           x = -c/b;
           printf ("One solution, x = ", x);
           return (1);
        }
}










