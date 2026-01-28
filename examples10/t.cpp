#include <iostream>
using namespace std;

class A {
  public:
    virtual void get_debug()
    {
        cout << "Task::get_debug()" << endl;
    };
    virtual ~A(){};
};

class Task : public virtual A {
  public:
    virtual void get_debug()
    {
        cout << "Task::get_debug()" << endl;
    };
    virtual ~Task(){};
};

class Displayed : public virtual A {
  public:
    virtual void get_debug()
    {
        cout << "Displayed::get_debug()" << endl;
    };
    virtual ~Displayed(){};
};

class Satellite : public Task, public Displayed {
  public:
    virtual void get_debug()
    {
        cout << "Satellite::get_debug()" << endl;
    };
};

int main()
{
    Satellite s;
    Satellite* sp = &s;
    Task* t = &s;
    Displayed* d = &s;
    t->get_debug();
    d->get_debug();
    sp->Displayed::get_debug();
}
