#include <iostream>
using namespace std;

void fun(char c)
{
    cout << "fun(char) called" << endl;
}

void fun(int c)
{
    cout << "fun(int) called" << endl;
}

int main()
{
    fun(10);
    fun('0');
}
