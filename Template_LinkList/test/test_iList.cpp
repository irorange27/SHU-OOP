#include <iostream>
#include "../src/LinkList.h"

using namespace std;
int main()
{
    cout << "Test for type int list:\n";
    LinkList<int> a(1);
    LinkList<int> b(2);
    cout << a;
    cout << "\n-------End--------\n";
    return 0;
}