#include <iostream>
#include<iomanip>
#include"vector.h"
using namespace std;

int main()
{
    double e;
    Vector a(5),b(6),d(5);
    Vector c(a);
    a.show();
    b.show();
    c.show();
    d.show();
    e=InMultiply(a,d);
    cout<<e<<endl;
    return 0;
}
