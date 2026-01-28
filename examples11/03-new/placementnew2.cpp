#include <iostream>
#include <new>
#include <string>
using namespace std;

int main()
{
    alignas(string) char buf[sizeof(string)];
    string* s = new (&buf) string; // construct an string at .buf;. invokes:
                                   // operator new(sizeof(string),buf);
    *s = "hello";
    cout << *s << endl;
    s->~string();
};
