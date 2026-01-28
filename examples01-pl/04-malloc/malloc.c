#include <stdio.h>
#include <stdlib.h>

int main()
{
    double* a = NULL;
    int n;
    int i;
    FILE* infile = fopen("ala", "r");
    if (fscanf(infile, "%d\n", &n) != 1)
        abort();
    a = (double*)malloc(n * sizeof(double));
    if (a == NULL)
        abort();
    for (i = 0; i < n; i++)
        if (1 != fscanf(infile, "%lf ", /*a+i */ &(a[i])))
            abort();
    for (i = 0; i < n; i++)
        printf("%f ", a[i]);
    printf("\n");
    free(a);
    fclose(infile);
    return 0;
}
