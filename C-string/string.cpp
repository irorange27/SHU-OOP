#include <iostream>
#include <cstring>
#include "string.h"
using namespace std;

MyString::MyString(const char *s) // 构造函数
{
    str = new char[strlen(s) + 1];
    strcpy(str, s);
    cout << "构造：\"" << str << "\"。" << endl;
}

MyString::MyString(const MyString &pn) // 深拷贝构造
{
    str = new char[strlen(pn.str) + 1];
    strcpy(str, pn.str);
    cout << "拷贝构造：\"" << str << "\"。" << endl;
}

MyString::~MyString() // 析构
{
    cout << "析构：\"" << str << "\"。" << endl;
    if (str)
        delete[] str;
}

MyString & MyString::operator=(const MyString &pn) //深赋值运算
{
    cout << "深赋值运算：\"" << pn.str << "\"。" << endl;
    if (&pn != this)
    {
        delete[] str;
        str = new char[strlen(pn.str) + 1];
        strcpy(str, pn.str);
    }
    return *this;
}

void MyString::show() const //输出
{
    cout << str << endl;
}

MyString & MyString::operator+=(const MyString &b) //重载+=
{
    *this =*this + b;
    return *this;
}

MyString operator+(const MyString &s1,const MyString &s2) //重载+
{
    MyString res;
    res.str = new char[strlen(s1.str) + strlen(s2.str) + 1];
    strcpy(res.str, s1.str);
    strcat(res.str, s2.str);
    return res;
}
