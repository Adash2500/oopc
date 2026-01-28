#include <iostream>

namespace ours {
class example {
    int a = 0;
    friend std::ostream& operator<<(std::ostream& o, example a);
};

std::ostream& operator<<(std::ostream& o, example a)
{
    o << a.a;
    return o;
}
} // namespace ours

int main()
{
    std::cout << 10;

    std::cout.operator<<(10);

    ours::example e, f, g;

    std::cout << e << f << g;

    ((std::cout << e) << f) << g;

    ours::operator<<(ours::operator<<(ours::operator<<(std::cout, e), f), g);
}
