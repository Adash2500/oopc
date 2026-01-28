#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    auto f = [](int x, int y) {
        int z = x + y;
        return z + x;
    };
    cout << f(3, 4) << endl;
};
