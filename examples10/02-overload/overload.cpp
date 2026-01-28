#include <string>
using namespace std;

class base {
  public:
    void f(int*){};
};

class derived : public base {
  public:
    void f(const string&){};
    using base::f;
};

int main()
{
    base a;
    derived b;
    string c;
    int* d = NULL;
    a.f(d);
    b.f(c);
    b.f(d);
    return 0;
}
