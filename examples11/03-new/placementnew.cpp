#include <iostream>
#include <new>
#include <string>
using namespace std;

int main()
{
    char buf[sizeof(string)];
    string* s = new (buf)
        string; // construct an string at .buf;. invokes: operator
                // new(sizeof(string),buf); actually undefined behaviour -
                // alignment restrictions might not be fulfilled
    *s = "hello";
    cout << *s << endl;
    s->~string();
};
