#include <iostream>
using namespace std;

class X {
  protected:
    int val;

  public:
    X(int v) : val(v){};
    virtual void f(double a)
    {
        cout << a + val << endl;
    }
    virtual ~X(){};
};

class Y : public X {
  public:
    Y(int v) : X(v){};
    void f(double a)
    {
        cout << 2 * a + val << endl;
    }
};

typedef void (X::*pf)(double); // pointer to member

void test(X* p, X* q)
{
    pf m = &X::f;
    (p->*m)(6.0);
    (q->*m)(7.0);
}

int main()
{
    X i(3);
    Y j(4);
    test(&i, &j);
}
