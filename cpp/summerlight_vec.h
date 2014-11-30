#ifndef _summer_vector
#define _summer_vector

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;
class vec
{
    int n_dim;
    double *d_pt;

    void errorhandle(const int n)
    {
        cout << "Logic error code = " << n << endl;
    }

  public:
      //====================
      // Constructors
      vec(){this->n_dim=0;} // empty constructor
      vec(const int n)
      {
          this->n_dim = n;
          this->d_pt = new double[n];
      }
      vec(const vec& v) // copy constructor
      {
          this->n_dim = v.n_dim;
          d_pt = new double[this->n_dim];
          memmove((void *)this->d_pt, (void *)v.d_pt, sizeof(double)*(this->n_dim));
      }

      vec(const int n, const double *pt)
      {
          this -> n_dim = n;
          this->d_pt = new double[n];
          memmove((void *)this->d_pt, (void*)pt, sizeof(double)*this->n_dim);
      }
      //====================
      // utility number function, operators
      inline double*& elements() {return this->d_pt;}
      inline int n() const {return this->n_dim;}
      inline int& n() {return this->n_dim;}
      inline double& operator[](const int n) {return this->d_pt[n];}
      inline double operator[](const int n) const {return this->d_pt[n];}

      inline double& operator()(const int n) {return this->d_pt[n];}
      inline double operator()(const int n) const {return this->d_pt[n];}

      double abs() const
      {
          int sum=0;
          for (int i=0; i<this->n_dim;i++)
          {
              sum += this->d_pt[i] * this->d_pt[i];
          }
          return sqrt(sum);
      }
      vec& operator=(const vec& v)
      {
          if(this->n_dim != v.n_dim)
          {
              errorhandle(101);
              exit(101);
          }
          memmove((void *)this->d_pt, (void*)v.d_pt, sizeof(double)*this->n_dim);
          return *this;
      }

      vec& operator+=(const vec& v)
      {
          if(this->n_dim != v.n_dim)
          {
              errorhandle(102);
              exit(102);
          }
          for(int i=0; i<this->n_dim; i++) this->d_pt[i] += v.d_pt[i];
          return *this;
      }

      vec& operator-=(const vec& v)
      {
          if(this->n_dim != v.n_dim)
          {
              errorhandle(102);
              exit(102);
          }
          for(int i=0; i<this->n_dim; i++) this->d_pt[i] -= v.d_pt[i];
          return *this;
      }

    /*
      double operator*(const vec& v)
      {
          if(this->n_dim != v.n_dim)
          {
              errorhandle(104);
              exit(104);
          }
          double sum = 0.0;
          for(int i = 0; i < this->n_dim;i++) sum += (this->d_pt[i] * v.d_pt[i]);
          return sum;
      }*/
      // ===================
      // define friends
      // ===================
};

vec& operator*(const vec& v1, const vec& v2)
{
    double* arrayy = new double[3];
    vec temp = vec(3);
    arrayy[0] = v1[1] * v2[2] - v1[2] * v2[1];
    arrayy[1] = v1[2] * v2[0] - v1[0] * v2[2];
    arrayy[2] = v1[0] * v2[1] - v1[1] * v2[0];
    temp.elements() = arrayy;
    return temp;
}

ostream& operator<<(ostream& oss, const vec& v)
{
    //oss << "vector dimension = " << v.n() << endl;
    oss << "Vector(";
    for (int i =0; i < v.n(); i++)
    {
        oss << right << v[i];
        if (i!=v.n()-1) oss << ", ";
    }
    oss << ")" << endl;
}

istream& operator>>(istream& iss, vec& v)
{
    int dimm;
    double *elements;
    cout << "Input the dimension of the vector: ";
    iss >> dimm;
    v.n() = dimm;
    elements = new double[dimm];
    for (int i = 0; i < v.n(); i++)
    {
        cout << "Input the " << i+1 << "th element: ";
        iss >> elements[i];
    }
    v.elements() = elements;
}
#endif // _summer_vector
