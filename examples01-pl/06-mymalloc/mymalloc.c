#include "mymalloc.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct _blkdata {
    unsigned long size; /* rozmiar bloku wlaczajac naglowek */
    unsigned int flags;
} blkdata;
#define MM_OCCUPIED 1
#define MM_LAST 2

static void* begin;

int mymalloc_init(unsigned long size)
{
    blkdata* b;
    assert(size > 0);
    begin = sbrk(size);
    if (!begin)
        return 0;
    b = (blkdata*)begin;
    b->size = size;
    b->flags = MM_LAST;
    return 1;
};

void* mymalloc(unsigned long size)
{
    blkdata* b = (blkdata*)begin;
    printf("Request to allocate %lu bytes\n", size);
    while (1) {
        if ((b->size > size + sizeof(blkdata)) && !(b->flags & MM_OCCUPIED)) {
            unsigned long after = b->size - size - sizeof(blkdata);
            if (after > sizeof(blkdata)) {
                blkdata* na = (blkdata*)((void*)b + size + sizeof(blkdata));
                na->flags = 0;
                if (b->flags & MM_LAST)
                    na->flags |= MM_LAST;
                na->size = after;
                b->size = size + sizeof(blkdata);
                b->flags = MM_OCCUPIED;
                return ((void*)b) + sizeof(blkdata);
            }
            else /* wez caly blok */
            {
                b->flags |= MM_OCCUPIED;
                return ((void*)b) + sizeof(blkdata);
            }
        };
        if (b->flags & MM_LAST)
            break;
        b = (blkdata*)((void*)b + b->size);
    };
    return NULL;
}

void myfree(void* ptr)
{
    blkdata* b;
    blkdata* nextb = NULL;
    blkdata* prevb = NULL;
    if (ptr == NULL)
        return;
    b = (blkdata*)(ptr - sizeof(blkdata));
    printf("Request to free %lu bytes at the address %p\n",
           b->size - sizeof(blkdata), b);
    if ((void*)b != begin) {
        /* znajdz poprzedni blok */
        prevb = (blkdata*)begin;
        while (1) {
            blkdata* next;
            assert(!(prevb->flags & MM_LAST));
            next = (blkdata*)((void*)prevb + prevb->size);
            if (next == b)
                break;
            prevb = next;
        };
    };
    /* znajdz nastepny blok */
    if (!(b->flags & MM_LAST))
        nextb = (blkdata*)((void*)b + b->size);
    /* zaznacz blok jako wolny */
    b->flags &= ~MM_OCCUPIED;
    /* skonsoliduj z nastepnym */
    if (nextb && !(nextb->flags & MM_OCCUPIED)) {
        if (nextb->flags & MM_LAST)
            b->flags = MM_LAST;
        b->size += nextb->size;
    }
    /* skonsoliduj z poprzednim */
    if (prevb && !(prevb->flags & MM_OCCUPIED)) {
        if (b->flags & MM_LAST)
            prevb->flags |= MM_LAST;
        prevb->size += b->size;
    };
}

static void* copyrealloc(void* ptr, unsigned long size, unsigned long oldsize)
{
    void* blk = mymalloc(size);
    if (blk == NULL)
        return NULL;
    memcpy(blk, ptr, oldsize);
    myfree(ptr);
    return blk;
}

void* myrealloc(void* ptr, unsigned long size)
{
    blkdata* b;
    if (ptr == NULL)
        return mymalloc(size);
    b = (blkdata*)(ptr - sizeof(blkdata));
    printf("Request to reallocate %lu bytes to %lu bytes, old address=%p\n",
           b->size - sizeof(blkdata), size, b);
    if (size == 0) {
        myfree(ptr);
        return NULL;
    };
    if (size <= b->size - sizeof(blkdata)) /* zmniejszenie bloku */
    {
        unsigned long after = b->size - size - sizeof(blkdata);
        blkdata* nextb = NULL;
        if (!(b->flags & MM_LAST))
            nextb = (blkdata*)((void*)b + b->size);
        blkdata* na = ((void*)b) + size + sizeof(blkdata);
        if (nextb && !(nextb->flags & MM_OCCUPIED))
        /* skonsoliduj z nastepnym */
        {
            unsigned int flags = nextb->flags;
            unsigned long size = after + nextb->size;
            na->flags = flags;
            na->size = size;
            b->size = size + sizeof(blkdata);
        }
        else if (after > sizeof(blkdata)) {
            na->flags = 0;
            if (b->flags & MM_LAST)
                na->flags |= MM_LAST;
            na->size = after;
            b->size = size + sizeof(blkdata);
            b->flags = MM_OCCUPIED;
        }
        return ptr;
    }
    else /* zwiekszenie bloku */
    {
        blkdata* next = (blkdata*)((void*)b + b->size);
        if (!(b->flags & MM_LAST) && !(next->flags & MM_OCCUPIED)) {
            unsigned long totalsize = b->size + next->size;
            unsigned long after = totalsize - size - sizeof(blkdata);
            if (size + sizeof(blkdata) >
                totalsize) /* brak miejsca w nastepnym bloku */
                return copyrealloc(ptr, size, b->size - sizeof(blkdata));
            if (next->flags & MM_LAST)
                b->flags |= MM_LAST;
            if (after > sizeof(blkdata)) {
                blkdata* na = (blkdata*)((void*)b + size + sizeof(blkdata));
                na->flags = 0;
                if (b->flags & MM_LAST)
                    na->flags |= MM_LAST;
                na->size = after;
                b->size = size + sizeof(blkdata);
                b->flags = MM_OCCUPIED;
            }
            else
                b->size += next->size;
            return ptr;
        }
        else /* nastepny zajety albo biezacy ostatni */
            return copyrealloc(ptr, size, b->size - sizeof(blkdata));
    }
}

void mymalloc_dump()
{
    blkdata* b = (blkdata*)begin;
    unsigned long totalsize = 0;
    printf("Mymalloc block list dump\n");
    while (1) {
        printf("Block at the address %p flags %c%c size %lu\n", b,
               (b->flags & MM_OCCUPIED) ? 'O' : 'F',
               (b->flags & MM_LAST) ? 'L' : ' ', b->size);
        totalsize += b->size;
        if (b->flags & MM_LAST)
            break;
        b = (blkdata*)((void*)b + b->size);
    };
    printf("Total size:%lu\n", totalsize);
}
