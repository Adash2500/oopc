#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers = {1, 2, 3, 4};
    int sum = 0;
    for_each(numbers.begin(), numbers.end(), [&sum](int x) { sum += x; });
    cout << sum << endl;
};
