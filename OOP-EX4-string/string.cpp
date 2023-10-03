#include <iostream>
#include <cstring>
#include "string.h"
using namespace std;

MyString::MyString(const char *s) {
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}

MyString::MyString(const MyString &other) {
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
}

MyString::~MyString() {
    delete[] str;
}

MyString &MyString::operator=(const MyString &other) {
    if (this != &other) {
        delete[] str;
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }
    return *this;
}

void MyString::show() const {
    std::cout << str << std::endl;
}

int MyString::length() const {
    return strlen(str);
}

const char *MyString::c_str() const {
    return str;
}

MyString &MyString::operator+=(const MyString &other) {
    *this = *this + other;
    return *this;
}

MyString operator+(const MyString &str1, const MyString &str2) {
    MyString result;
    result.str = new char[strlen(str1.str) + strlen(str2.str) + 1];
    strcpy(result.str, str1.str);
    strcat(result.str, str2.str);
    return result;
}