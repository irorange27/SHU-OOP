#include <iostream>
#include "String.h"

using namespace std;

int main(int argc, char** argv)
{
    String init;
    String initWithValue1("Hello");
    String initWithValue2(" world!");    
    String copyInit(initWithValue1);

    cout << init << endl;
    cout << initWithValue1 << endl;
    cout << initWithValue2 << endl;


    return 0;
}

