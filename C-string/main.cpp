#include <iostream>
#include <cstring>
#include "string.h"
using namespace std;
int main()
{
    MyString a("123"),b("567"),e("4");
    a.show();
    MyString c=a;
    c.show();
    c=b;
    c.show();
    MyString d=a+e;
    d+b;
    d.show();
    return 0;
}
