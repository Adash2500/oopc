#include <iomanip>
#include <iostream>
#include <vector> // for vector template definition
using namespace std;

int main()
{
    vector<int> a;
    vector<int> b;

    a.push_back(3);
    b.push_back(4);

    cout << (a < b) << endl;
}
