#include <iostream>
using namespace std;
#include "vector.h"

void printvector(vector v)
{
    cout << v << endl;
}

int main()
{
    vector a(10);
    cout << a << endl;
    a[0] = 15;
    a[5] = 32;
    vector b(10);
    b = a;
    printvector(b);
}
