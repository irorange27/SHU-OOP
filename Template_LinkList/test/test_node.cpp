#include <iostream>
#include <cstddef>
#include "../src/LinkList.h"

using namespace std;

int main(int argc, char** argv)
{
    cout << "Test for node class:\n";
    LinkList<int> a(1);
    LinkList<int> b(3);
    LinkList<int> c(b);
    a.append(2);
    a.show();
    LinkList<int> d(a);
    d.show();

    d.extend(b);
    d.show();
    a.extend(d);
    a.show();
    
    cout << a.head()->data();
    cout << a.head()->next()->data();
    cout << a.head()->next()->prev()->data();
    cout << a.curNode()->data();
    cout << a.curNode()->prev()->data();
    cout << a.tail()->data();
    cout << a.tail()->prev()->data() << endl;

    a.popleft();
    a.popleft();
    a.append(4).append(5);
    a.extend(a);
    a.show();
    a.extend(d);
    a.show();

    cout << "\n------end-------\n";
    return 0;
}
