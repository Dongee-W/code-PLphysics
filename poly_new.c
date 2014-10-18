#include <stdio.h>
#include <stdlib.h>

struct aa {int n; double *a};
typedef struct aa polynomial;

struct bb {double x, y;};
typedef struct bb twod;

double fabs(double);
void print(polynomial);
twod polyn(double x, polynomial);
polynomial inputpolyn(void);

int main()
{
    /*
    double x, *coef, fx, df, dx;
    int nd, i;
    char achr;

    coef = inputpolyn(&nd);
    print(nd, coef);
    */
    double x;
    twod values;
    polynomial poly;
    poly = inputpolyn();
    print(poly);

    printf("x value: ");
    scanf("%lf", &x);

    values = polyn(x, poly);
    printf("function value: %lf\n", values.x);
    printf("function derivative: %lf\n", values.y);

    /*
    x = 0.1234556;
    do
    {
        polyn(x, coef, nd, &fx, &df);
        dx = fx / df;
        x -= dx;
    } while(fabs(dx) > 1.0e-8);
    printf("root = %.15lf check = %.15lf\n", x, fx);
    */

    return 0;
}
 polynomial inputpolyn()
 {  int i;
    polynomial poly;

    printf("Type the order of the polynomial : ");
    scanf("%d", &poly.n);
    poly.a = calloc(poly.n+1, sizeof(double));
    for (i=poly.n; i>=0; i--)
    {
        printf("ceof(%d) = ", i);
        scanf("%lf", poly.a+i);
    }
    return poly;
 }

twod polyn(double x, polynomial poly)
{
    double sum, dsum;
    int i;
    twod value;

    dsum = 0.0;
    sum = poly.a[poly.n];
    for (i=poly.n; i>0; i--)
    {
        dsum = dsum * x + sum;
        sum = sum * x + poly.a[i-1];
    }

    value.x = sum;
    value.y = dsum;
    return value;
}
void print(polynomial poly)
{
    int i;
    printf("The order of the polynomial = %d\n", poly.n);
    for (i=poly.n; i>=0; i--)
    {
        printf("ceof(%d) = %lf\n", i, poly.a[i]);
    }
    return;
}
