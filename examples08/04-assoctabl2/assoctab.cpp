#include <iostream>
using namespace std;
#include "assoctab.h"

assocTab::assocTab()
{
    head = NULL;
}

void assocTab::clear()
{
    while (head) {
        node* t = head->next;
        delete head;
        head = t;
    };
}

assocTab::~assocTab()
{
    clear();
}

void assocTab::insert(const char* key, int value)
{
    node* newnode = new node(key);
    newnode->next = head;
    head = newnode;
    head->val = value;
}

void assocTab::swap(assocTab& l)
{
    node* t = head;
    head = l.head;
    l.head = t;
}

assocTab::assocTab(const assocTab& l)
{
    node *src, **dst;
    head = NULL;
    src = l.head;
    dst = &head;
    try {
        while (src) {
            *dst = new node(*src);
            src = src->next;
            dst = &((*dst)->next);
        }
    }
    catch (...) {
        clear();
        throw;
    };
}

assocTab& assocTab::operator=(const assocTab& l)
{
    if (&l == this)
        return *this;
    assocTab t(l);
    swap(t);
    return *this;
}

assocTab::node* assocTab::find(const char* key) const
{
    node* c = head;
    while (c) {
        if (!strcmp(c->key, key))
            return c;
        c = c->next;
    };
    return NULL;
}

int& assocTab::operator[](const char* key)
{
    node* c = find(key);
    if (!c) {
        insert(key, 0);
        c = head;
    };
    return c->val;
}
