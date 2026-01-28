#include <functional>
#include <unordered_set>
using namespace std;
#include "employee.h"

int main()
{
    Employee Ben("Ben", "Keller", "000-00-0000");
    Employee Bill("Bill", "McQuain", "111-11-1111");
    Employee Dwight("Dwight", "Barnette", "888-88-8888");

    unordered_set<Employee, decltype([](const Employee& o) {
                      return std::hash<std::string>()(o.FirstName) ^
                             (std::hash<std::string>()(o.LastName) << 1) ^
                             (std::hash<std::string>()(o.ID) << 2);
                  })>
        S;
    S.insert(Bill);
    S.insert(Dwight);
    S.insert(Ben);

    for (auto i : S)
        cout << i << endl;
}
