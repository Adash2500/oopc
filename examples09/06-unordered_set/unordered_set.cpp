#include <functional>
#include <unordered_set>
using namespace std;
#include "employee.h"

struct EmpHash {
    std::size_t operator()(const Employee& o) const
    {
        return std::hash<std::string>()(o.FirstName) ^
               (std::hash<std::string>()(o.LastName) << 1) ^
               (std::hash<std::string>()(o.ID) << 2);
    }
};

void EmpsetPrint(const unordered_set<Employee, EmpHash> S, ostream& Out);

int main()
{
    Employee Ben("Ben", "Keller", "000-00-0000");
    Employee Bill("Bill", "McQuain", "111-11-1111");
    Employee Dwight("Dwight", "Barnette", "888-88-8888");

    unordered_set<Employee, EmpHash> S;
    S.insert(Bill);
    S.insert(Dwight);
    S.insert(Ben);
    EmpsetPrint(S, cout);
}

void EmpsetPrint(const unordered_set<Employee, EmpHash> S, ostream& Out)
{
    unordered_set<Employee, EmpHash>::const_iterator It;
    for (It = S.begin(); It != S.end(); ++It)
        Out << *It << endl;
}
