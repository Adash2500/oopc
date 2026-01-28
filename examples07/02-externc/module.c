#include <stdio.h>

int fun1()
{
    return 15;
}

void fun2(int a)
{
    printf("%d\n", a);
}

int fun3(double b)
{
    printf("%f\n", b);
    return (int)b;
}
