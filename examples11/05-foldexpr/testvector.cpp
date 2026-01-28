#include <iostream>
using namespace std;
#include "vector.h"

template <class C> void printvector(vector<C> v)
{
    cout << v << endl;
}

int main()
{
    vector<int> a(10);
    cout << a << endl;
    a[0] = 15;
    a[5] = 32;
    vector<int> b(10);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    a.push_back(9);
    a.push_back(10);
    cout << a.push_back(11) << endl;
    cout << a.push_back(12, 13, 14) << endl;
    int arg = 15;
    a.push_back(arg);
    b = a;
    printvector(b);
}
