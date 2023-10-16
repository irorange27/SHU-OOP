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
        cout<<"向量维数至少为1"<<endl;
    }
    catch(double)
    {
        cout<<"下标越界"<<endl;
    }
    catch(char)
    {
        cout<<"两个向量的维数不匹配"<<endl;
    }
    catch(float)
    {
        cout<<"向量外积运算的维数不为3"<<endl;
    }
    return 0;
}
