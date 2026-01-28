#include "stack.h"
#include <assert.h>

#define STACKSIZE 20
static int top; /* pierwsze wolne miejsce na stosie */
static int dane[STACKSIZE];

void init()
{
    top = 0;
}

void finalize() {}

void clear()
{
    top = 0;
}

void push(int a)
{
    assert(top < STACKSIZE);
    dane[top++] = a;
}

int pop()
{
    assert(top > 0);
    return dane[--top];
}
