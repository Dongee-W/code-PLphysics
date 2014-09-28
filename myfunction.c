// Yan-Ten Lu 2014/09/22
#include <stdio.h>   // standard i/o head file
#include <math.h>
double myexp(double t)
{
    int i;
    double term, sum;
    term = 1.0;
    sum = term;
    i = 1;
    while( fabs(term) > 1.0e-16)
    {
        term *=  t / (double)i;
        sum +=  term;
        i++;
    }
    return sum;
}
double mycos(double t)
{
    int i;
    double term, sum;
    term = 1.0;
    sum = term;
    i = 0;
    while( fabs(term) > 1.0e-16)
    {
        i += 2;  // 2, 4, 6, 8, 10, .....
        term *=  (-1.0) * t * t  / (double)(i*(i-1));
        sum +=  term;
    }
    return sum;
}
double mysin(double t)
{
    int i;
    double term, sum;
    term = t;
    sum = term;
    i = 1;
    while( fabs(term) > 1.0e-16)
    {
        i += 2;  // 3, 5, 7, 9, 11, 13, ....
        term *=  (-1.0) * t * t  / (double)(i*(i-1));
        sum +=  term;
    }
    return sum;
}
int main()
{
    double x, y;
    printf("\nInput x : ");
    scanf("%lf", &x);
    y = myexp(x);
    printf("myexp(%lf) = %.15lf  exact = %.15lf\n", x, y, exp(x));
    printf("mycos(%lf) = %.15lf  exact = %.15lf\n", x, mycos(x), cos(x));
    printf("mysin(%lf) = %.15lf  exact = %.15lf\n", x, mysin(x), sin(x));
    return 0;
}
