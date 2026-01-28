#include <stdio.h>
#include <stdlib.h>

char* itoa(int a)
{
    char* buf = (char*)malloc(20);
    snprintf(buf, 20, "%d", a);
    return buf;
}

int main()
{
    char *w1, *w2;
    printf("%s %s\n", w1 = itoa(17), w2 = itoa(15));
    free(w1);
    free(w2);
    return 0;
}
