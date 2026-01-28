#include <iostream>
#include <memory>
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

int genexc()
{
    cout << "genexc()" << endl;
    throw 0;
    return 0;
}

void fun1(const unique_ptr<Example>& ptr, int b) {}

void fun2(int b, const unique_ptr<Example>& ptr) {}

int main()
{
    cout << "One:" << endl;
    try {
        fun1(make_unique<Example>(), genexc()); // OK
    }
    catch (...) {
    }

    cout << "Two:" << endl;
    try {
        fun2(genexc(), make_unique<Example>(3)); // OK
    }
    catch (...) {
    }
}
