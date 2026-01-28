#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

auto fun()
{
    int sum = 12;
    return [sum](int x) { return sum + x; };
}

int main()
{
    cout << fun()(4) << endl;
};
