// Rk4 solve 2nd order ODE
#include <stdio.h>
#include <math.h>
#include "twod.h"
#define GAMMA  0.4
#define OMEGA2 1.0
#define T0 0.0
#define V0 0.0
#define X0 1.0
double applyforce(double t)
{
    return 1.0 * cos(2.5 * t);
}
twod slopef(twod y, double t)
{
    twod f;
    f.x = y.y;
    f.y = applyforce(t) - 2.0 * GAMMA * y.y - OMEGA2 * y.x;
    return f;
}
double analytic(double t)
{
    double w, A, B;
    w = sqrt(OMEGA2 - GAMMA * GAMMA);
    A = X0;
    B = (V0 + GAMMA * X0) / w;

    return exp(-GAMMA * t) * ( A * cos(w*t) + B * sin(w*t));
}
int main()
{
    int i, nfinal;
    twod k1, k2, k3, k4, kavg;
    double t, tau, tau2, tt, tfinal;
    twod y, yt;

    tau = 0.01;
    tau2 = tau / 2.0;
    tfinal = 20.0 / GAMMA;
    nfinal = tfinal / tau + 10;
// rk4 initialization
    t = T0;
    y.x = X0;
    y.y = V0;

    FILE *fp;
    fp = fopen("result.txt", "w");
    for (i=0; i<nfinal; i++)
    {
        tt = t;
        yt = y;
        k1 = slopef(yt, tt);
 //***********************************************k2
        tt = t + tau2;
        yt = twodplus(y, twodxd(k1, tau2));
        k2 = slopef(yt, tt);
//************************************************k3
//       tt = t + tau2;
        yt = twodplus(y , twodxd(k2 , tau2));
        k3 = slopef(yt, tt);
//************************************************k4
        tt = t + tau;
        yt = twodplus(y , twodxd(k3 , tau));
        k4 = slopef(yt, tt);
//************************************************x1, y1
        kavg = twodplus(twodxd(twodplus(k2, k3), 2.0), twodplus(k1, k4));
 //       v = v + (k1 + k4 + 2.0 * (k2+k3)) * tau / 6.0;
        y = twodplus(y, twodxd(kavg, tau/6.0));
        t = T0 + (i+1) * tau;


        if ((i+1) % 2 == 0) fprintf( fp,"  %10.5lf   %20.15lf  %20.15lf\n", t, y.x, y.y);

    }
    fclose(fp);
    return 0;
}
