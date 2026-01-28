#include <stdlib.h>

int main()
{
    char a[10];
    a[10] = 'c';
    free(a);
    return 0;
}
