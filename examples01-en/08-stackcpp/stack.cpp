#include "stack.h"
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

stack::stack()
{
    this->top = 0;
    cout << "stack::stack() called\n";
}

stack::~stack()
{
    cout << "stack::~stack() called\n";
}

void stack::clear()
{
    this->top = 0;
}

void stack::push(int a)
{
    assert(this->top < STACKSIZE);
    this->data[this->top++] = a;
}

int stack::pop()
{
    assert(this->top > 0);
    return this->data[--this->top];
}
