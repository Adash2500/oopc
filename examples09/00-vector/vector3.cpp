#include <iomanip>
#include <iostream>
#include <vector> // for vector template definition
using namespace std;

int main()
{
    vector<int> Y;
    for (int m = 0; m < 100; m++) {
        Y.insert(Y.begin(), m);
        cout << setw(3) << m << setw(5) << Y.capacity() << endl;
    }
}
