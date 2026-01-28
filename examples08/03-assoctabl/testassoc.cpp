#include <iostream>
using namespace std;
#include "assoctab.h"

int main()
{
    assocTab a1, a2;
    a1["ala"] = 1;
    a1["ola"] = 2;
    cout << a1["ala"] << " " << a1["ola"] << " " << a1["ula"] << endl;
    a2 = a1;
    a2["ula"]++;
    cout << a2["ala"] << " " << a2["ola"] << " " << a2["ula"] << endl;
}
