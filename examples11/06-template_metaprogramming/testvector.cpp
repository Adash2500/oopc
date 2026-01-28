#include <iostream>
using namespace std;
#include "vector.h"

template <class C> void printvector(vector<C> v)
{
    cout << v << endl;
}

int main()
{
    vector<string> a(0);
    vector<string> b(0);
    a.push_back("1");
    a.push_back("2");
    a.push_back("3");
    a.push_back("4");
    a.push_back("5");
    a.push_back("6");
    a.push_back("7");
    a.reserve(10); // to avoid reallocation and reference invalidation

    std::tuple<string&, string&, string&> c = a.push_back("8", "9", "10");

    printvector(a);

    get<0>(c) = "108";
    get<1>(c) = "109";
    get<2>(c) = "110";

    printvector(a);

    a.reserve(12);
    auto [x, y] = a.push_back("11", "12");
    x = "111";
    y = "112";

    string arg = "13";
    a.push_back(arg);
    b = a;
    printvector(b);
}
