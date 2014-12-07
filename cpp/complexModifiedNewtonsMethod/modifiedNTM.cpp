#include <complex>
#include "polynomial.h"
using namespace std;
int main()
{
    complex<double> xtry, x(2.0), sum, dx;
    double tolerance = 10e-8;
    complex<double> *root;
    polynomial p1(2);
    cin >> p1;
    root = new complex<double>[p1.poly_degree];

    //double ff[3] = {1, 2, 3};
    //p1.coef = ff;
    //cout << abs(x);
    //

    xtry = complex<double> (0.2, 0.56);
    for (int nr = 0; nr < p1.poly_degree; nr++)
    {
        x = xtry;
        do
        {
            sum = 0.0;
            for (int i = 0; i < nr; i++ ) sum += 1.0 / (x - root[i]);
            dx = p1.f(x) / (p1.fderivative(x) - p1.f(x) * sum);
            x -= dx;
        } while(abs(dx) > tolerance);
        root[nr] = x;
        cout << "root[" << nr << "] = " << x << "   Check = " << p1.f(x) <<endl;
    }

}
