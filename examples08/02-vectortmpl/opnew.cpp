#include <iostream>
using namespace std;

class Object {
  public:
    Object()
    {
        cout << "Object::Object() called" << endl;
    }
};

int main()
{
    Object* p1 = new Object;    /* Object::Object() used */
    Object* p2 = new Object();  /* Object::Object() used */
    int* p3 = new int;          /* not initialized ! */
    int* p4 = new int();        /* initialized to zero */
    Object* p5 = new Object[7]; /* Object::Object() used 7 times */
    int* p6 = new int[7];       /* not initialized ! */
    int* p7 = new int[7]();     /* initialized to zero */

    if (*p3)
        cout << "*p3 nonzero" << endl;
    if (*p4)
        cout << "*p4 nonzero" << endl;
    if (*p6)
        cout << "*p6 nonzero" << endl;
    if (*p7)
        cout << "*p7 nonzero" << endl;

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete[] p5;
    delete[] p6;
    delete[] p7;
}
