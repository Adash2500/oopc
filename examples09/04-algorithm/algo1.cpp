#include <iostream>
#include <vector>
using namespace std;

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
    for (idx = v.begin(); idx != v.end(); ++idx)
        cout << *idx << endl;
    total = 0;
    for (idx = v.begin(); idx != v.end(); ++idx)
        total = total + *idx;
    cout << "Sum = " << total << endl;
}
