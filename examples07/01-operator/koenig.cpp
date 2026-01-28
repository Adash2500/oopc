#include <iostream>
#include <string>

namespace Chrono {
class Date { /* ... */
};
bool operator==(const Date&, const std::string&);
std::string format(const Date&); // make string representation
// ...
} // namespace Chrono

void f(Chrono::Date d, std::string s)
{
    if (d == s) {
        // ...
    }
    else if (d == "August 4, 1914") {
        // ...
    }
}
