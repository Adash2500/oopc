#include <iostream>
using namespace std;
#include "vector.h"

template <class C> void printvector(vector<C> v)
{
    cout << v << endl;
}

class Dummy {
  public:
    Dummy()
    {
        cout << "Dummy default constructor" << endl;
    };
    Dummy(const Dummy&)
    {
        cout << "Dummy copy constructor" << endl;
    };
    Dummy(Dummy&&)
    {
        cout << "Dummy move constructor" << endl;
    };
    Dummy(int)
    {
        cout << "Dummy int constructor" << endl;
    };

    Dummy(int, double)
    {
        cout << "Dummy int,double constructor" << endl;
    };
};

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
    a.push_back(11);
    int arg = 13;
    a.push_back(arg);
    b = a;
    printvector(b);
    vector<string> c(10);
    vector<string> d(15);
    c[0] = "ala";
    c[9] = "ma kota";

    const char* long_string = "long_string_that_will_not_use_SSO";

    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);
    c.push_back(long_string);

    string l(long_string);
    c.push_back(l);
    c.emplace_back(long_string);
    cout << "About to assign vector" << endl;
    d = c;
    cout << "Vector assigned" << endl;
    printvector(d);

    vector<Dummy> dd(10);
    Dummy dv;
    dd.push_back(dv);
    dd.push_back(Dummy());
    dd.push_back(7);
    dd.emplace_back(7);
    dd.emplace_back(7, 3.5);
    dd.emplace_back(7);
    dd.emplace_back(7);
}
