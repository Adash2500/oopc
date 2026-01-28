#include <iostream>
#include <stdexcept>
#include <vector> // for vector template definition
using namespace std;

int main()
{
    int MaxCount = 100;
    vector<int> iVector(MaxCount);
    try {
        for (int Count = 0; Count < 2 * MaxCount; Count++) {
            cout << iVector.at(Count);
        }
    }
    catch (out_of_range&) {
        cerr << "Range error" << endl;
    }
}
