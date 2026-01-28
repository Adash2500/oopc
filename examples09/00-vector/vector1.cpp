#include <iostream>
#include <vector> // for vector template definition
using namespace std;

int main()
{
    int MaxCount = 100;
    vector<int> iVector(MaxCount);
    for (int Count = 0; Count < 2 * MaxCount; Count++) {
        cout << iVector[Count];
    }
}
