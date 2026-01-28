#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;

class Employee {
    string name;
    char middle_initial;
    long department;

  public:
    Employee(const string& n, int dept) : name(n), department(dept){};
    void print() const
    {
        cout << name << '\t' << department << endl;
    }
};

class Manager : public Employee {
    short level;

  public:
    Manager(const string& name, int dept, int l)
        : Employee(name, dept), level(l){};
    void print() const
    {
        Employee::print();
        cout << "\tlevel" << level << endl;
    }
};

void print_list(set<Employee*>& s)
{
    for (Employee* p : s)
        p->print();
}

int main()
{
    Employee e("Brown", 1234);
    Manager m("Smith", 1234, 2);
    set<Employee*> empl;
    empl.insert(&e);
    empl.insert(&m);
    print_list(empl);
}
