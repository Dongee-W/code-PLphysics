#include<stdio.h>

int main()
{
    double fx, dfx, x, acoef[200];
    int n, i;
    printf("Input the order of the polynomial: ");
    scanf("%d", &n);
    for(i=1; i <= n + 1; i++)
    {
        printf("%d order coefficient: ", i - 1);
        scanf("%lf", &acoef[i-1]);

    }
    printf("Input value of x: ");
    scanf("%lf", &x);
    polynomial(x, acoef, n + 1, &fx, &dfx);
    printf("%lf    %lf", fx, dfx);


}

void polynomial(double x, double *a, int np, double *fx, double *dfx)
{
    double sum, dsum;
    int i;
    for (i = np; i>0; i--)
    {
        dsum = dsum * x + sum;
        sum = sum * x + a[i-1];
    }
    *fx = sum;
    *dfx = dsum;
}
