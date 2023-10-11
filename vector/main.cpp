#include <iostream>
#include<iomanip>
#include"vector.h"
using namespace std;

int main()
{
    double e,f;
    Vector a(4),b(6),d(5);
    Vector c(a);
    cout<<"ÇëÊäÈëa"<<endl;
    cin>>a>>b;
    e=InMultiply(a,d);
    f=b.radius();
    cout<<a<<b<<c<<d<<e<<f<<endl;
    return 0;
}
