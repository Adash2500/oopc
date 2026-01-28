#include <iostream>
using namespace std;
#include <string.h>

template <typename... T> struct wrapper;

template <> struct wrapper<> {
    static void mprintf(const char* s)
    {
        cout << s;
    };
};

template <typename... T> struct wrapper<int, T...> {
    static void mprintf(const char* s, int d1, T... data)
    {
        while (*s && *s != '%')
            if (*s)
                cout << *s++;
        if (*s == '%')
            s++;
        cout << d1;
        wrapper<T...>::mprintf(s, data...);
    };
};

template <typename... T> struct wrapper<double, T...> {
    static void mprintf(const char* s, double d1, T... data)
    {
        while (*s && *s != '%')
            if (*s)
                cout << *s++;
        if (*s == '%')
            s++;
        cout << d1;
        wrapper<T...>::mprintf(s, data...);
    };
};

template <typename... T> void mprintf(const char* s, T... data)
{
    wrapper<T...>::mprintf(s, data...);
}

int main()
{
    wrapper<double, double, int>::mprintf("ala % ma % kota i % psa\n", 10, 15.0,
                                          20);
    mprintf("ala % ma % kotów i % psów\n", 10.1, 15.4, 20);
}
