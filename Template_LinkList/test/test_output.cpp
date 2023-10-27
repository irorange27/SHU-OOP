#include <iostream>
#include "../src/LinkList.h"

using namespace std;

int main(int argc, char** argv)
{
    cout << "Test for overload operator<< :\n";
    LinkList<int> a(1);
    LinkList<int> b(2);
    cout << a;
    cin >> a;
    cout << "------end--------\n";
    return 0;
}