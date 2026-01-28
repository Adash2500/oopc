#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Example {
  public:
    Example()
    {
        cout << "Example::Example()" << endl;
    }

    Example(int a)
    {
        cout << "Example::Example(" << a << ")" << endl;
    }

    ~Example()
    {
        cout << "Example::~Example()" << endl;
    }
};

int main()
{
    vector<unique_ptr<Example>> v(10);
    cout << v.size() << endl;

    v.push_back(make_unique<Example>(1));
    v.push_back(unique_ptr<Example>(new Example()));
    cout << v.size() << endl;

    vector<unique_ptr<Example>> w = move(v);

    cout << v.size() << endl;
    cout << w.size() << endl;

    unique_ptr<Example> a(move(w[10]));
}
