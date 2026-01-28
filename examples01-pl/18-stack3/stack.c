#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 20

struct stack_handle {
    int top; /* pierwsze wolne miejsce na stosie */
    int dane[STACKSIZE];
};

struct stack_handle*
init()
{
    struct stack_handle* s =
        (struct stack_handle*)malloc(sizeof(struct stack_handle));
    s->top = 0;
    return s;
}

void finalize(struct stack_handle* s)
{
    free(s);
}

void clear(struct stack_handle* s)
{
    s->top = 0;
}

void push(struct stack_handle* s, int a)
{
    assert(s->top < STACKSIZE);
    s->dane[s->top++] = a;
}

int pop(struct stack_handle* s)
{
    assert(s->top > 0);
    return s->dane[--s->top];
}
