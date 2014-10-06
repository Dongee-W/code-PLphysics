// Polynomial
// Yan-Ten Lu 2014-09-29
#include <stdio.h>
#include <stdlib.h>
double fabs(double);
void print(int, double*);
void polyn(double, double*, int, double*, double*);
double* inputpolyn(int *);
int main()
{
    double x, *coef, fx, df, dx;
    int nd, i;
    char achr;

    coef = inputpolyn(&nd);
    print(nd, coef);
/*
    while (1) // 1 -- TRUE;  0 -- FALSE .... infinite loop
    {
        printf("Type x = "); // prompt
        scanf("%lf", &x);
        polyn(x, coef, nd, &fx, &df);
        printf("f(%lf) = %.15lf   fp(%lf) = %.15lf\n",x, fx, x, df);
        printf("type 'c' to continue, 'q' to quit :");
        fflush(stdin); scanf("%c", &achr); // stdin= 0 stdout=1 stderr=2
        if (achr == 'q') break;
    }
*/


    int nr, count, j;
    double *root, summ;
    root = calloc(nd, sizeof(double));

    nr = 0;
    do{
        count = 0;
        x = 0.1234556;
        do
        {
            polyn(x, coef, nd, &fx, &df);
            for(j=0; j<nr; j++) summ += 1.0/(x-root[j]);
            dx = fx / (df - fx * summ);
            x -= dx;
            count ++; if(count>100) exit(1);
        } while(fabs(dx) > 1.0e-6);

        root[nr] = x;
        nr ++;
        printf("root = %.15lf check = %.15lf\n", x, fx);
    } while (nr <= nd);

    printf("%d", nd);
    int gg;
    for(gg=0; gg<=nr;gg++) printf("#%d root = %d\n", gg, root[gg]);

    return 0;
}

 double*inputpolyn(int*n)
 {  int nd, i;
    double *coef;
    printf("Type the order of the polynomial : ");
    scanf("%d", &nd);
    coef = calloc(nd+1, sizeof(double));
    for (i=nd; i>=0; i--)
    {
        printf("ceof(%d) = ", i);
        scanf("%lf", coef+i);
    }
    *n = nd;
    return coef;
 }
void polyn(double x, double *a, int n, double *f, double *df)
{
    double sum, dsum;
    int i;
    dsum = 0.0;
    sum = a[n];
    for (i=n; i>0; i--)
    {
        dsum = dsum * x + sum;
        sum = sum * x + a[i-1];
    }
    *f = sum;
    *df = dsum;
}
void print(int n, double *a)
{
     int i;
    printf("The order of the polynomial = %d\n", n);
    for (i=n; i>=0; i--)
    {
        printf("ceof(%d) = %lf\n", i, a[i]);
    }
    return;
}
