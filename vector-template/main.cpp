#include <iostream>
#include"vector templete.h"
using namespace std;

int main()
{
    try
    {
        Vector<double> a(5);
        cin>>a;
        cout <<a[6]<< endl;
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
