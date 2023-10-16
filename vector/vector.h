#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include<iostream>
using namespace std;
class Vector
{
public:
    Vector(int a=1)throw(int);
    Vector(const Vector &);
    Vector & operator=(const Vector &);
    virtual ~Vector();
    Vector & operator+=(const Vector &);
    Vector & operator-=(const Vector &);
    double radius()const;
    double & operator[](const int &)const throw(double);
    Vector & Add(const int &);
    Vector & Delete(const int &);
    friend Vector operator+(const Vector &,const Vector &)throw(char);
    friend Vector operator-(const Vector &,const Vector &)throw(char);
    friend Vector operator*(const double &,const Vector &);
    friend Vector operator*(const Vector &,const double &);
    friend Vector operator*(const Vector &,const Vector &)throw(float);
    friend double InMultiply(const Vector &,const Vector &)throw(char);
    friend bool operator<(const Vector &,const Vector &)throw(char);
    friend bool operator>(const Vector &,const Vector &)throw(char);
    friend bool operator<=(const Vector &,const Vector &)throw(char);
    friend bool operator>=(const Vector &,const Vector &)throw(char);
    friend bool operator==(const Vector &,const Vector &)throw(char);
    friend bool operator!=(const Vector &,const Vector &)throw(char);
    friend ostream & operator<<(ostream &,const Vector &);
    friend istream & operator>>(istream &,Vector &);
private:
    double *vec;
    int n;
};


#endif // VECTOR_H_INCLUDED
