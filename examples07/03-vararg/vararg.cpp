#include <cstdarg>
#include <iostream>
#include <sstream>
using namespace std;

extern void error(int...);
const char* Null_cp = 0;
int main(int argc, char* argv[])
{
    switch (argc) {
    case 1:
        error(0, argv[0], Null_cp);
        break;
    case 2:
        error(0, argv[0], argv[1], Null_cp);
        break;
    default:
        ostringstream s;
        s << argc - 1;
        string ss = s.str();
        error(1, argv[0], "with", ss.c_str(), "arguments", Null_cp);
    }
    //...
}
void error(
    int severity...) // "severity" followed by a zeroterminated list of char*s
{
    va_list ap;
    va_start(ap, severity); // arg startup
    for (;;) {
        char* p = va_arg(ap, char*);
        if (p == 0)
            break;
        cerr << p << ' ';
    }
    va_end(ap); // arg cleanup
    cerr << '\n';
    if (severity)
        exit(severity);
}
