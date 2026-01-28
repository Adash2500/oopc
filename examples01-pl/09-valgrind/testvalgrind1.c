#include <stdlib.h>

int main()
{
    char* a = (char*)malloc(10);
    a[10] = 'c';
    return 0;
}
