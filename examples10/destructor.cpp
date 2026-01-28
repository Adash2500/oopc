#include <iostream>
using namespace std;

class base {
  public:
    base()
    {
        cout << "base()" << endl;
    }
    virtual void f()
    {
        cout << "base" << endl;
    };
    void g()
    {
        this->f();
    };
    virtual ~base()
    {
        this->f();
        cout << "~base()" << endl;
    };
};

class derived : public base {
    int* ptr;

  public:
    derived()
    {
        ptr = new int(7);
        cout << "derived()" << endl;
    };
    ~derived()
    {
        delete ptr;
        cout << "~derived()" << endl;
    };
    void f() override
    {
        cout << "derived " << *ptr << endl;
    };
};

int main()
{
    base* ptr = new derived;
    ptr->g();
    ptr->f();
    delete ptr;
}
