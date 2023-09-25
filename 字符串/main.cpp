#include <iostream>
#include <iomanip>
#include"string.h"
using namespace std;

int main()
{
    String a("abcd"),b("efgh");
    String c(b);
    c="xswl";
    a.show();
    c.UpperString();
    c=4*a;
    c.show();
    return 0;
}
