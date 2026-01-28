#include <iostream>
#include <string>
using namespace std;

string getword()
{
    string s;
    cin >> s;
    return s;
}

int main()
{
    cout << "Podaj slowo" << endl;
    cout << "Podane slowo to:" << getword() << endl;
}
