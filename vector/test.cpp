#include "vector.h"

int main(int argc, char** argv)
{
    Vector init;
    Vector initWithValue(4);
    Vector copyInit(initWithValue);

    cout << init << endl;
    cout << initWithValue << endl;
    cout << copyInit << endl;

    Vector a(1);
    Vector b1(2);
    Vector b2(2);
    Vector b3;
    
    b1 + b2;    // normal

    b3 = b1 + b2;  // error

    b1 += b2;       // error
    


    return 0;
}