#include <iostream>
using namespace std;
#include "t.h"

void fun(Task*);

class Satellite : public Task, public Displayed {
    // virtual void get_debug(){cout<<"Satellite::get_debug()"<<endl;};
};

int main()
{
    Satellite s;
    fun(&s);
}
