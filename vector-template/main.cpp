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
