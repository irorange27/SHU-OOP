#include <iostream>
#include<iomanip>
#include"vector.h"
using namespace std;

int main()
{
    try
    {
        Vector a(3),b(3),d(5),f(6);
        cout<<"Entering vector a"<<endl;
        //cin>>a>>b;
        cout<<a<<b<<endl;
        d=a*b;
        cout<<d<<endl;
    }
    catch(int)
    {
        cout<<"����ά������Ϊ1"<<endl;
    }
    catch(double)
    {
        cout<<"�±�Խ��"<<endl;
    }
    catch(char)
    {
        cout<<"����������ά����ƥ��"<<endl;
    }
    catch(float)
    {
        cout<<"������������ά����Ϊ3"<<endl;
    }
    return 0;
}
