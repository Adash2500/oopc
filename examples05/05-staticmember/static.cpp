#include <iostream>
using namespace std;

class example {
    static int a;
    int v;

  public:
    static int getStatic()
    {
        return a;
    };
    static void setStatic(int p)
    {
        a = p;
    };
    example(int p) : v(p){};
    int fun()
    {
        return v + a;
    };
};

int example::a = 42;

int main()
{
    example e(27);
    example f(47);
    cout << example::getStatic() << endl;
    f.setStatic(34);
    cout << e.fun() << endl;
}
