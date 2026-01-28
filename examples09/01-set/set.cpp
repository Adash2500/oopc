#include <functional>
#include <set>
using namespace std;
#include "employee.h"

void EmpsetPrint(const set<Employee> S, ostream& Out);

int main()
{
    Employee Ben("Ben", "Keller", "000-00-0000");
    Employee Bill("Bill", "McQuain", "111-11-1111");
    Employee Dwight("Dwight", "Barnette", "888-88-8888");
    set<Employee> S;
    S.insert(Bill);
    S.insert(Dwight);
    S.insert(Ben);
    EmpsetPrint(S, cout);
}

void EmpsetPrint(const set<Employee> S, ostream& Out)
{
    set<Employee>::const_iterator It;
    for (It = S.begin(); It != S.end(); ++It)
        Out << *It << endl;
}
