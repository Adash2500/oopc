#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__
#include <iostream>
#include <string>

struct Employee {
    std::string FirstName, LastName, ID;
    Employee(const std::string& fn, const std::string& ln, const std::string& I)
        : FirstName(fn), LastName(ln), ID(I){};
    friend std::ostream& operator<<(std::ostream& o, const Employee& e)
    {
        o << e.FirstName << " " << e.LastName << " " << e.ID;
        return o;
    };

    bool operator==(const Employee& o) const
    {
        return (FirstName == o.FirstName) && (LastName == o.LastName) &&
               (ID == o.ID);
    }
};
#endif /* __EMPLOYEE_H__ */
