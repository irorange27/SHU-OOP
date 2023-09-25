#include<iostream>
#include<iomanip>
#include<cstring>
#include"string.h"
using namespace std;
String::String(const char *a)
{
    str=new char[strlen(a)+1];
    strcpy(str,a);
    cout<<"Constructing an object of String \""<<str<<"\"."<<endl;
}
String::String(const String &a)
{
    str=new char[strlen(a.str)+1];
    strcpy(str,a.str);
    cout<<"Copy constructing an object of String \""<<str<<"\"."<<endl;
}
String::~String()
{
    cout<<"Destructing an object of String \""<<str<<"\"."<<endl;
    if(str)
        delete [] str;
}
String & String::operator=(const String &a)
{
    cout<<"Assign an object of String \""<<a.str<<"\"."<<endl;
    if(&a!=this)
    {
        if(str)
            delete [] str;
        str=new char[strlen(a.str)+1];
        strcpy(str,a.str);
    }
    return *this;
}
void String::show()const
{
    cout<<str<<endl;
}
void String::UpperString()
{
    cout<<"Upper \""<<str<<"\"->\"";
    strupr(str);
    cout<<str<<"\"."<<endl;
}
String String::operator+(const String &a,const String &b)
{
    String temp;
    temp.str=new char[strlen(b.str)+strlen(a.str)+1];
    strcpy(temp.str,a.str);
    strcpy(temp.str,b.str);
    return temp;
}
String String::operator*(const int &a,const String &b)
{
    String temp;
    int i=0;
    temp.str=new char[a*strlen(b.str)+1];
    for(i=0;i<=a,i++)
        strcpy(temp.str,b.str);
    return temp;
}
