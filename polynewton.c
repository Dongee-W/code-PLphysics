#include<stdio.h>

int main()
{
    double fx, dfx, acoef[200];
    int n, i;
    printf("Input the order of the polynomial: ");
    // Scan for the order
    scanf("%d", &n);
    // Read in the coefficients
    for(i=1; i <= n + 1; i++)
    {
        printf("%d order coefficient: ", i - 1);
        scanf("%lf", &acoef[i-1]);
    }

    // Start the newton's method
    int in = 0;
    double x, dx;
    x = 0.0;
    polynomial(x, acoef, n + 1, &fx, &dfx);

    do
    {
        dx = fx / dfx;
        x -= dx;
        in++;
        polynomial(x, acoef, n + 1, &fx, &dfx);
        if (in > 100) break;
    } while(fabs(dx) > 1.0e-10);

    // Output result
    if (in <= 100)
        printf("root=%.15lf   check value=%.15lf\n", x, fx);
    else printf("Newton's Method failed!!\n");
}

void polynomial(double x, double *a, int np, double *fx, double *dfx)
{
    double sum = 0.0, dsum = 0.0;
    int i;
    for (i = np; i>0; i--)
    {
        dsum = dsum * x + sum;
        sum = sum * x + a[i-1];
    }
    *fx = sum;
    *dfx = dsum;
}
