#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include<iostream>
using namespace std;
class Vector
{
public:
    Vector(int a=1);
    Vector(const Vector &);
    Vector & operator=(const Vector &);
    virtual ~Vector();
    Vector & operator+=(const Vector &);
    Vector & operator-=(const Vector &);
    double radius()const;
    friend Vector operator+(const Vector &,const Vector &);
    friend Vector operator-(const Vector &,const Vector &);
    friend Vector operator*(const double &,const Vector &);
    friend double InMultiply(const Vector &,const Vector &);
    friend bool operator<(const Vector &,const Vector &);
    friend bool operator>(const Vector &,const Vector &);
    friend bool operator<=(const Vector &,const Vector &);
    friend bool operator>=(const Vector &,const Vector &);
    friend bool operator==(const Vector &,const Vector &);
    friend bool operator!=(const Vector &,const Vector &);
    friend ostream & operator<<(ostream &,const Vector &);
    friend istream & operator>>(istream &,Vector &);
private:
    double *vec;
    int n;
};


#endif // VECTOR_H_INCLUDED
