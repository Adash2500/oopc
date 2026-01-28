#include <iostream>
#include <memory>
using namespace std;

#include "ival_box.h"

unique_ptr<Ival_box> ivalBoxFactory();

void fun()
{
    auto s = ivalBoxFactory();
    s->reset_value(12);
    s->prompt();
    cout << s->get_value() << endl;
};
