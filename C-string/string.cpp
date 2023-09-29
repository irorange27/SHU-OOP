#include <iostream>
#include <cstring>
#include "string.h"
using namespace std;

MyString::MyString(const char *s) // ���캯��
{
    str = new char[strlen(s) + 1];
    strcpy(str, s);
    cout << "���죺\"" << str << "\"��" << endl;
}

MyString::MyString(const MyString &pn) // �������
{
    str = new char[strlen(pn.str) + 1];
    strcpy(str, pn.str);
    cout << "�������죺\"" << str << "\"��" << endl;
}

MyString::~MyString() // ����
{
    cout << "������\"" << str << "\"��" << endl;
    if (str)
        delete[] str;
}

MyString & MyString::operator=(const MyString &pn) //�ֵ����
{
    cout << "�ֵ���㣺\"" << pn.str << "\"��" << endl;
    if (&pn != this)
    {
        delete[] str;
        str = new char[strlen(pn.str) + 1];
        strcpy(str, pn.str);
    }
    return *this;
}

void MyString::show() const //���
{
    cout << str << endl;
}

MyString & MyString::operator+=(const MyString &b) //����+=
{
    *this =*this + b;
    return *this;
}

MyString operator+(const MyString &s1,const MyString &s2) //����+
{
    MyString res;
    res.str = new char[strlen(s1.str) + strlen(s2.str) + 1];
    strcpy(res.str, s1.str);
    strcat(res.str, s2.str);
    return res;
}
