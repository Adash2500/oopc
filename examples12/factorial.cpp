#include <iostream>
using namespace std;

template <int N> constexpr int factorial()
{
    return N * factorial<N - 1>();
}

template <> constexpr int factorial<0>()
{
    return 1;
}

constexpr int fact2(int n)
{
    if (n > 0)
        return n * fact2(n - 1);
    else
        return 1;
}

int main()
{
    cout << factorial<7>() << endl;
}
