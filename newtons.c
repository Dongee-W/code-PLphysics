// 2014-09-22
// Newton's method solving f(x)=x-cos(x)
#include <stdio.h>
#include <math.h>
double mycos(double);
double mysin(double);
double f(double x)
{
    return x - mycos(x);
}
double fp(double x)
{
    return 1 + mysin(x);
}
int main()
{
    int i = 0;
    double x, dx;
    x = 0.0;
    do
    {
        dx = f(x) / fp(x);
        x -= dx;
        i++;
        if (i > 100) break;
    } while(fabs(dx) > 1.0e-10);
    if (i < 100) printf("root=%.15lf   check value=%.15lf\n", x, f(x));
    else printf("Newton's Method failed!!\n");
    return 0;
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
