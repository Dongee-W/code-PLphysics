// Rk4 solve 2nd order ODE
#include <stdio.h>
#include <math.h>
#define X0 0.0


struct ttt {  double u, v, w;};
typedef struct ttt rdd;

rdd rddplus(rdd v1, rdd v2)
{
    rdd v3;
    v3.u = v1.u + v2.u;
    v3.v = v1.v + v2.v;
    v3.w = v1.w + v2.w;
    return v3;
}

rdd rddxd(rdd v, double r)
{
    rdd w;
    w.u = v.u * r;
    w.v = v.v * r;
    w.w = v.w * r;
    return w;
}
rdd rddminus(rdd v1, rdd v2)
{
    rdd v3;
    v3.u = v1.u - v2.u;
    v3.v = v1.v - v2.v;
    v3.w = v1.w - v2.w;
    return v3;
}
double rdddot(rdd v1, rdd v2)
{
    return v1.u*v2.u + v1.v*v2.v + v1.w*v2.w;
}

double applyforce(double x)
{
    return 0;
}
rdd slopef(rdd y, double x)
{
    rdd f;
    f.u = y.v;
    f.v = y.w;
    f.w = exp(-x) - 4 * y.w - 5 * y.v - 2 * y.u;
    return f;
}

double analytic(double x)
{
    return 1.0 / 2.0 * x * x * exp(-x);
}

int main()
{
    int i, nfinal;
    rdd k1, k2, k3, k4, kavg;
    double x, tau, tau2, xx, xfinal;
    rdd y, yt;

    tau = 0.001;
    tau2 = tau / 2.0;
    xfinal = 1.0;
    nfinal = xfinal / tau + 1;
// rk4 initialization
    x = X0;
    y.u = 0;
    y.v = 0;
    y.w = 1;

    FILE *fp;
    fp = fopen("result.txt", "w");
    for (i=0; i<nfinal; i++)
    {
        xx = x;
        yt = y;
        k1 = slopef(yt, xx);
 //***********************************************k2
        xx = x + tau2;
        yt = rddplus(y, rddxd(k1, tau2));
        k2 = slopef(yt, xx);
//************************************************k3
//       tt = t + tau2;
        yt = rddplus(y , rddxd(k2 , tau2));
        k3 = slopef(yt, xx);
//************************************************k4
        xx = x + tau;
        yt = rddplus(y , rddxd(k3 , tau));
        k4 = slopef(yt, xx);
//************************************************x1, y1
        kavg = rddplus(rddxd(rddplus(k2, k3), 2.0), rddplus(k1, k4));
 //       v = v + (k1 + k4 + 2.0 * (k2+k3)) * tau / 6.0;
        y = rddplus(y, rddxd(kavg, tau/6.0));
        x = X0 + (i+1) * tau;


        if ((i+1) % 10 == 0) {
            fprintf( fp,"  %10.5lf   %20.15lf  %20.15lf\n", x, y.u, analytic(x));
            //printf("%lf\n", analytic(x));
        }

    }
    fclose(fp);
    return 0;
}
