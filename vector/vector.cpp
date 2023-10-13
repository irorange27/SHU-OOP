#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include"vector.h"

using namespace std;

/* Initialize vector with random value */
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
Vector & Vector::operator+=(const Vector &a)
{
    *this=*this+a;
    return *this;
}
Vector & Vector::operator-=(const Vector &a)
{
    *this=*this-a;
    return *this;
}
double Vector::radius()const
{
    double temp=0;
    for(int i=0;i<n;i++)
        temp=temp+vec[i]*vec[i];
    temp=sqrt(temp);
    return temp;
}
Vector operator+(const Vector &a,const Vector &b)
{
    Vector temp;
    if(a.n!=b.n)
        return temp;
    else
    {
        for(int i=0;i<a.n;i++)
            temp.vec[i]=a.vec[i]+b.vec[i];
    }
    return temp;
}
Vector operator-(const Vector &a,const Vector &b)
{
    Vector temp;
    if(a.n!=b.n)
        return temp;
    else
    {
        for(int i=0;i<a.n;i++)
            temp.vec[i]=a.vec[i]-b.vec[i];
    }
    return temp;
}
Vector operator*(const double &a,const Vector &b)
{
    Vector temp;
    for(int i=0;i<b.n;i++)
        temp.vec[i]=a*b.vec[i];
    return temp;
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
bool operator<(const Vector &a,const Vector &b)
{
    Vector temp;
    temp=a-b;
    return temp.radius()<0;
}
bool operator>(const Vector &a,const Vector &b)
{
    Vector temp;
    temp=a-b;
    return temp.radius()>0;
}
bool operator<=(const Vector &a,const Vector &b)
{
    Vector temp;
    temp=a-b;
    return temp.radius()<=0;
}
bool operator>=(const Vector &a,const Vector &b)
{
    Vector temp;
    temp=a-b;
    return temp.radius()>=0;
}
bool operator==(const Vector &a,const Vector &b)
{
    Vector temp;
    temp=a-b;
    return temp.radius()==0;
}
bool operator!=(const Vector &a,const Vector &b)
{
    Vector temp;
    temp=a-b;
    return temp.radius()!=0;
}
ostream & operator<<(ostream &out,const Vector &a)
{
    if(a.n!=0)
    {
        cout<<"("<<a.vec[0];
        for(int i=1;i<a.n;i++)
            cout<<", "<<a.vec[i];
        cout<<")"<<endl;
    }
    return out;
}
// istream & operator>>(istream &in,Vector &a)
// {
//     int i=0;
//     char str[100];
//     in.getline(str,100,' ');
//     if(in==NULL)
//         return in;
//     a.n=atoi(str);
//     a.vec=new double [a.n];
//     for(i=0;i<=a.n-2;i++)
//     {
//         in.getline(str,100,' ');
//         if(in==NULL)
//         {
//             break;
//             return in;
//         }
//         else
//             a.vec[i]=atoi(str);
//     }
//     in.getline(str,100,'\n');
//     a.vec[i]=atoi(str);
//     return in;
// }
