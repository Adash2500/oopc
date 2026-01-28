#include <iostream>
using namespace std;
#include <string.h>

void mprintf(const char* s)
{
    cout << s;
}

template <typename C, typename... T>
void mprintf(const char* s, C d1, T... data)
{
    while (*s && *s != '%')
        if (*s)
            cout << *s++;
    if (*s == '%')
        s++;
    cout << d1;
    mprintf(s, data...);
}

int main()
{
    mprintf("ala % ma % kotów i % psów\n", 1, 2.5, 5.5);
}
