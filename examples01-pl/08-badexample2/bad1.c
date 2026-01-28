#include <stdio.h>
#include <stdlib.h>

char* itoa(int a)
{
    char buf[20];
    snprintf(buf, 20, "%d", a);
    return buf;
}

int main()
{
    printf("%s %s\n", itoa(17), itoa(15));
    return 0;
}
