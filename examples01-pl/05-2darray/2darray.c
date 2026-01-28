#include <stdio.h>
#include <stdlib.h>

int main()
{
    double** a = NULL;
    double** b = NULL;
    int rows = 3;
    int columns = 5;
    int i;
    a = (double**)malloc(rows * sizeof(double*));
    for (i = 0; i < rows; i++)
        a[i] = (double*)malloc(columns * sizeof(double));
    b = (double**)malloc(rows * sizeof(double*));
    b[0] = (double*)malloc(rows * columns * sizeof(double));
    for (i = 1; i < rows; i++)
        b[i] = b[i - 1] + columns;
    /* use a and b */
    for (i = 0; i < rows; i++)
        free(a[i]);
    free(a);
    free(b[0]);
    free(b);
    return 0;
}
