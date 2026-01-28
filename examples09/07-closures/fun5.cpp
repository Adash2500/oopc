#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class C {
    int c;

  public:
    C(int _c) : c(_c){};

    auto fun()
    {
        return [this](int x) { return c + x; };
    }

    void print(function<int(int)> f)
    {
        cout << fun()(3) << endl;
    }
};

int main()
{
    C c1(1);
    C c2(2);

    auto f = c2.fun();
    c1.print(f);
};
