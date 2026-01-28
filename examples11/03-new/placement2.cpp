#include <iostream>
#include <new>
#include <string>
using namespace std;

class Arena {
  public:
    virtual void* alloc(size_t s)
    {
        return malloc(s);
    };
    virtual void free(void* s)
    {
        ::free(s);
    };
};

class object {
  public:
    object()
    {
        throw 0;
    }
};

void* operator new(size_t sz, Arena* a)
{
    return a->alloc(sz);
}

void operator delete(void* s, Arena* a)
{
    a->free(s);
    cout << "operator delete called" << endl;
}

int main()
{
    Arena a;
    try {
        string* s = new (&a) string("s");
        object* o = new (&a) object;

        s->~string();
        o->~object();
        a.free(s);
        a.free(o);
    }
    catch (int) {
        cout << "Exception of type int caught" << endl;
    }
}
