#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void print(int i)
{
    cout << i << endl;
}

int main()
{
    vector<int> v;
    vector<int>::iterator idx;
    int i, total;
    cout << "Enter numbers, end with ^D" << endl;
    cout << "% ";
    while (cin >> i) {
        v.push_back(i);
        cout << "% ";
    }
    cout << endl << endl;
    cout << "Numbers entered = " << v.size() << endl;
    for_each(v.begin(), v.end(), print);
    total = accumulate(v.begin(), v.end(), 0);
    cout << "Sum = " << total << endl;
}
