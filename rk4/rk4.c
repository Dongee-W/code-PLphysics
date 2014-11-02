// Rk4 solve 1st order ODE
#include <stdio.h>
#include <math.h>
#define BETA 0.01
#define Gforce 9.8
#define T0 0.0
#define V0 0.0
double slopef(double v, double t)
{
    return -(BETA * v + Gforce);
}
double analytic(double t)
{
    double tt;
    tt = -(t * BETA);
    return (Gforce / BETA) * ( exp(tt) - 1.0);
}
int main()
{
    int i, nfinal;
    double k1, k2, k3, k4;
    double v, t, tau, tau2, vt, tt, tfinal;

    tau = 0.01;
    tau2 = tau / 2.0;
    tfinal = 5.0 / BETA;
    nfinal = tfinal / tau + 100;
// rk4 initialization
    t = T0;
    v = V0;
    for (i=0; i<nfinal; i++)
    {
        tt = t;
        vt = v;
        k1 = slopef(vt, tt);
 //***********************************************k2
        tt = t + tau2;
        vt = v + k1 * tau2;
        k2 = slopef(vt, tt);
//************************************************k3
//       tt = t + tau2;
        vt = v + k2 * tau2;
        k3 = slopef(vt, tt);
//************************************************k4
        tt = t + tau;
        vt = v + k3 * tau;
        k4 = slopef(vt, tt);
//************************************************x1, y1
        v += (k1 + k4 + 2.0 * (k2+k3)) * tau / 6.0;
        t = T0 + (i+1) * tau;
        if ((i+1) % 200 == 0) printf("  %10.5lf   %20.15lf  %20.15lf\n",t, v, analytic(t));
    }
    return 0;
}
