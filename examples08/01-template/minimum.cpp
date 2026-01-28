#include <iostream>
#include <string>
using namespace std;

template <class T> T minimum(T x, T y)
{
    if (x < y)
        return x;
    else
        return y;
}

int main()
{
    int x = 50, y = 30;
    string a = "hello", b = "goodbye";
    cout << "minimum for ints " << minimum(x, y) << endl;
    cout << "minimum for strings " << minimum(a, b) << endl;
}
