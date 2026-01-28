#include <iostream>
#include <new>
using namespace std;

void out_of_store()
{
    cerr << "operator new failed: out of store\n";
    throw bad_alloc();
}
int main()
{
    set_new_handler(out_of_store); // make out_of_store the new_handler
    for (;;)
        new char[10000];
    cout << "done\n";
}
