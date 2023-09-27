#include<iostream>
#include<iomanip>
#include"vector.h"
using namespace std;
Vector::Vector(int a)
{
    n=a;
    if(a<=0)
    {
        n=1;
        vec=NULL;
        return;
    }
    else
        vec=new double [n];
    for(int i=0;i<n;i++)
        vec[i]=rand()%10;
}
Vector::Vector(const Vector &a)
{
    n=a.n;
    if(n!=0)
    {
        vec=new double [n];
        for(int i=0;i<n;i++)
            vec[i]=a.vec[i];
    }
}
Vector::~Vector()
{
    if(vec)
        delete [] vec;
}
Vector & Vector::operator=(const Vector &a)
{
    n=a.n;
    if(&a!=this)
    {
        if(vec)
            delete [] vec;
        vec=new double [a.n];
        for(int i=0;i<n;i++)
            vec[i]=a.vec[i];
    }
    return *this;
}
void Vector::show() const
{
    if(n==0)
        return;
    else
        cout<<"("<<vec[0];
    for(int i=1;i<n;i++)
        cout<<", "<<vec[i];
    cout<<")"<<endl;
}
double InMultiply(const Vector &a,const Vector &b)
{
    double temp=0;
    if(a.n!=b.n)
        return 0;
    else
    {
        for(int i=0;i<a.n;i++)
            temp=temp+a.vec[i]*b.vec[i];
    }
    return temp;
}
