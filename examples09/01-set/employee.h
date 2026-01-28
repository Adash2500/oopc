#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__
#include <iostream>
#include <string>

class Employee {
    std::string FirstName, LastName, ID;

  public:
    Employee(const std::string& fn, const std::string& ln, const std::string& I)
        : FirstName(fn), LastName(ln), ID(I){};
    friend std::ostream& operator<<(std::ostream& o, const Employee& e)
    {
        o << e.FirstName << " " << e.LastName << " " << e.ID;
        return o;
    };
    bool operator<(const Employee& Other) const
    {
        return (ID < Other.ID);
    }
};

#endif /* __EMPLOYEE_H__ */
