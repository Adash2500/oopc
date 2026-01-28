#include <iostream>
using namespace std;

class a {
  public:
    void print1()
    {
        cout << "1" << endl;
    };
    virtual void print2()
    {
        cout << "2" << endl;
    };
};

class b : public a {
  public:
    void print1()
    {
        cout << "11" << endl;
    };
    void print2()
    {
        cout << "22" << endl;
    };
};

void fun(a* p)
{
    p->print1();
    p->print2();
}

int main()
{
    a aa;
    b bb;
    fun(&aa);
    fun(&bb);
    return 0;
}
