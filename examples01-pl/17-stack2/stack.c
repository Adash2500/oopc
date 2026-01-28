#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static int top; /* pierwsze wolne miejsce na stosie */
static int* dane;
static int size;

void init()
{
    top = 0;
    size = 0;
    dane = 0;
}

void finalize()
{
    free(dane);
}

void clear()
{
    top = 0;
}

void push(int a)
{
    if (top >= size) {
        int newsize = (size + 1) * 2;
        int* ndane = (int*)realloc(dane, newsize * sizeof(int));
        if (ndane)
            dane = ndane;
        else {
            free(dane);
            abort();
        }
        fprintf(stderr, "Rozmiar stosu %d -> %d\n", size, newsize);
        size = newsize;
    }
    dane[top++] = a;
}

int pop()
{
    assert(top > 0);
    return dane[--top];
}
