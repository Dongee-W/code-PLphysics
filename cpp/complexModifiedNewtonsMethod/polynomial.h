#include <complex>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;
struct polynomial
{
    int poly_degree;
    double *coef;

    polynomial() {this->poly_degree=0;}
    polynomial(const int n)
    {
        this->poly_degree = n;
        this->coef = new double[n+1];
    }
    polynomial(const int n, const double *pt)
    {
        this->poly_degree = n;
        this->coef = new double[n+1];
        memmove((void *)this->coef, (void*)pt, sizeof(double)*this->poly_degree);
    }

    complex<double> f(complex<double> x)
    {
        complex<double> sum(this->coef[this->poly_degree]);
        for (int i=this->poly_degree; i>0; i--)
        {
            sum = sum * x + this->coef[i-1];
        }
        return sum;
    }
    complex<double> fderivative(complex<double> x)
    {
        complex<double> sum(this->coef[this->poly_degree]), dsum(0.0);
        for (int i=this->poly_degree; i>0; i--)
        {
            dsum = dsum * x + sum;
            sum = sum * x + this->coef[i-1];
        }
        return dsum;
    }
    int n() {return this->poly_degree;}
};


istream& operator>>(istream& is, polynomial& poly)
{
    double *gg;
    cout << "Enter the degree: ";
    cin >> poly.poly_degree;
    gg = new double[poly.poly_degree+1];
    for (int i = poly.poly_degree; i>=0; i--)
    {
        cout << "Enter the " << i << "th order term coefficient: ";
        is >> gg[i];
    }
    poly.coef = gg;
}
