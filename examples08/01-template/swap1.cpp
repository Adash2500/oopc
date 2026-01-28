#include <iostream>
#include <string>
using namespace std;
template <class T> void swap_value(T& var1, T& var2)
{
    T temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}
int main()
{
    int int1 = 1, int2 = 2;
    cout << "original " << int1 << " " << int2 << endl;
    swap_value(int1, int2);
    cout << "after " << int1 << " " << int2 << endl;
    string s1 = "one", s2 = "two";
    cout << "original " << s1 << " " << s2 << endl;
    swap_value(s1, s2);
    cout << "after " << s1 << " " << s2 << endl;
}
