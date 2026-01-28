#include <stdio.h>

int* f1(int* a, const int* b)
{
    *a += *b;
    return a;
}

int* f2(int* a, const int* b)
{
    *a -= *b;
    return a;
}

int* (*fun(int s))(int*, const int*)
{
    if (s == 1)
        return f1;
    else
        return f2;
}

int main()
{
    int* (*(*fp2)(int))(int*, const int*) = fun;

    int a = 15;
    int b = 32;
    fp2(1)(&a, &b);
    fp2(2)(&b, &a);
    printf("%d %d\n", a, b);
    return 0;
}
