#ifndef VECTOR_TEMPLETE_H_INCLUDED
#define VECTOR_TEMPLETE_H_INCLUDED
#include<iostream>
#include<cmath>
using namespace std;
template<typename Type> class Vector
{
public:
    Vector(int a=1,const *x=NULL)throw(int)
    {
        if(a<=0)
            throw (int)1;
        n=a;
        vec=new Type [n];
        for(int i=0;i<n;i++)
            vec[i]=(x==NULL)? 0 : x[i];
    }
    Vector(const Vector &a)
    {
        n=a.n;
        if(n!=0)
        {
            vec=new Type [n];
            for(int i=0;i<n;i++)
                vec[i]=a.vec[i];
        }
    }
    Vector & operator=(const Vector &a)
    {
        n=a.n;
        if(&a!=this)
        {
            if(vec)
                delete [] vec;
            vec=new Type [a.n];
            for(int i=0;i<n;i++)
                vec[i]=a.vec[i];
        }
        return *this;
    }
    virtual ~Vector()
    {
        if(vec)
            delete [] vec;
    }
    Vector & operator+=(const Vector &a)
    {
        *this=*this+a;
        return *this;
    }
    Vector & operator-=(const Vector &a)
    {
        *this=*this-a;
        return *this;
    }
    double radius()const
    {
        double temp=0;
        for(int i=0;i<n;i++)
            temp=temp+vec[i]*vec[i];
        temp=sqrt(temp);
        return temp;
    }
    Type & operator[](const int &i)const throw(double)
    {
        if(i>=n||i<0)
            throw (double)0;
        return vec[i];
    }
    Vector & Add(const int &a)
    {
        int i=0;
        const int b=n;
        Vector temp=*this;
        if(vec)
            delete [] vec;
        vec=new Type [n+a];
        n=a+b;
        for(i=0;i<b;i++)
            vec[i]=temp.vec[i];
        for(i=b;i<b+a;i++)
            vec[i]=0;
        return *this;
    }
    Vector & Delete(const int &a)
    {
        const int b=n;
        Vector temp=*this;
        if(vec)
            delete [] vec;
        vec=new Type [b-a];
        n=b-a;
        for(int i=0;i<b-a;i++)
            vec[i]=temp.vec[i];
        return *this;
    }
    friend Vector operator+(const Vector &a,const Vector &b)throw(char)
    {
        if(a.n!=b.n)
            throw (char)-1;
        Vector temp(a.n);
        for(int i=0;i<a.n;i++)
            temp.vec[i]=a.vec[i]+b.vec[i];
        return temp;
    }
    friend Vector operator-(const Vector &a,const Vector &b)throw(char)
    {
        if(a.n!=b.n)
            throw (char)-1;
        Vector temp(a.n);
        for(int i=0;i<a.n;i++)
            temp.vec[i]=a.vec[i]-b.vec[i];
        return temp;
    }
    friend Vector operator*(const double &a,const Vector &b)
    {
        Vector temp(b.n);
        for(int i=0;i<b.n;i++)
            temp.vec[i]=a*b.vec[i];
        return temp;
    }
    friend Vector operator*(const Vector &b,const double &a)
    {
        Vector temp(b.n);
        for(int i=0;i<b.n;i++)
            temp.vec[i]=a*b.vec[i];
        return temp;
    }
    friend Vector operator*(const Vector &a,const Vector &b)throw(float)
    {
        if(a.n!=3||b.n!=3)
            throw (float)-1;
        Vector temp(3);
        temp.vec[0]=a.vec[1]*b.vec[2]-a.vec[2]*b.vec[1];
        temp.vec[1]=a.vec[2]*b.vec[0]-a.vec[0]*b.vec[2];
        temp.vec[2]=a.vec[0]*b.vec[1]-a.vec[1]*b.vec[0];
        return temp;
    }
    friend Type InMultiply(const Vector &a,const Vector &b)throw(char)
    {
        Type temp=0;
        if(a.n!=b.n)
            throw (char)-1;
        else
        {
            for(int i=0;i<a.n;i++)
                temp=temp+a.vec[i]*b.vec[i];
        }
        return temp;
    }
    friend bool operator<(const Vector &a,const Vector &b)throw(char)
    {
        if(a.n!=b.n)
            throw (char)-1;
        Vector temp(a.n);
        temp=a-b;
        return temp.radius()<0;
    }
    friend bool operator>(const Vector &a,const Vector &b)throw(char)
    {
        if(a.n!=b.n)
            throw (char)-1;
        Vector temp(a.n);
        temp=a-b;
        return temp.radius()>0;
    }
    friend bool operator<=(const Vector &a,const Vector &b)throw(char)
    {
        if(a.n!=b.n)
            throw (char)-1;
        Vector temp(a.n);
        temp=a-b;
        return temp.radius()<=0;
    }
    friend bool operator>=(const Vector &a,const Vector &b)throw(char)
    {
        if(a.n!=b.n)
            throw (char)-1;
        Vector temp(a.n);
        temp=a-b;
        return temp.radius()>=0;
    }
    friend bool operator==(const Vector &a,const Vector &b)throw(char)
    {
        if(a.n!=b.n)
            throw (char)-1;
        Vector temp(a.n);
        temp=a-b;
        return temp.radius()==0;
    }
    friend bool operator!=(const Vector &a,const Vector &b)throw(char)
    {
        if(a.n!=b.n)
            throw (char)-1;
        Vector temp(a.n);
        temp=a-b;
        return temp.radius()!=0;
    }
    friend ostream & operator<<(ostream &out,const Vector &a)
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
    friend istream & operator>>(istream &in,Vector &a)
    {
        int i=0;
        char str[100];
        in.getline(str,100,' ');
        /*if(in==NULL)
            return in;*/
        a.n=atof(str);
        a.vec=new Type [a.n];
        for(i=0;i<=a.n-2;i++)
        {
            in.getline(str,100,' ');
            /*if(in==NULL)
            {
                break;
                return in;
            }
            else*/
                a.vec[i]=atof(str);
        }
        in.getline(str,100,'\n');
        a.vec[i]=atof(str);
        return in;
    }
private:
    Type *vec;
    int n;
};
#endif // VECTOR_TEMPLETE_H_INCLUDED
