#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

template <class T> class greater_than {
    T reference;

  public:
    greater_than(const T& v) : reference(v) {}
    bool operator()(const T& w)
    {
        return w > reference;
    }
};

int main()
{
    srandom(time(NULL));
    vector<long> v(10);
    generate(v.begin(), v.end(), random);
    cout << count_if(v.begin(), v.end(), greater_than<long>(RAND_MAX >> 1))
         << endl;
};
