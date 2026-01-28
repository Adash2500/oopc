#include <iostream>
using namespace std;

class A { // no constructor
          // ...
};
class B {
  public:
    B()
    {
        cout << "B::B()" << endl;
    } // default constructor
      // ...
};
class C {
  public:
    C(int)
    {
        cout << "C::C(int)" << endl;
    }; // no default constructor
};
class D : virtual public A, virtual public B, virtual public C {
  public:
#ifndef ERROR
    D() : C(15)
    {
        cout << "D::D()" << endl;
    }; // ok
#else
    D() : {/* ... */}; // error: no default constructor for C
#endif
    D(int i) : C(i){/* ... */}; // ok
                                // ...
};
class E : public D {
  public:
#ifdef ERROR
    E(){/* ... */}; // error: no default constructor for C
#endif
    E(int i) : C(i)
    {
        cout << "E::E(int)" << endl;
    }; // ok
       // ...
};

int main()
{
    D d(3);
    E e(4);
}
