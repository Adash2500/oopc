#include "mymalloc.h"
#include <assert.h>

int main()
{
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    void* p5;

    if (!mymalloc_init(10000000))
        abort();
    mymalloc_dump();
    p1 = mymalloc(100);
    mymalloc_dump();
    p2 = mymalloc(200);
    mymalloc_dump();
    p3 = mymalloc(300);
    mymalloc_dump();
    myfree(p2);
    mymalloc_dump();
    p2 = mymalloc(150);
    mymalloc_dump();
    p2 = myrealloc(p2, 170);
    mymalloc_dump();
    p2 = myrealloc(p2, 300);
    mymalloc_dump();
    p4 = mymalloc(10000);
    mymalloc_dump();
    p5 = mymalloc(50000);
    mymalloc_dump();
    myfree(p4);
    mymalloc_dump();
    p4 = mymalloc(7000);
    mymalloc_dump();
    myfree(p2);
    mymalloc_dump();
    myfree(p1);
    mymalloc_dump();
    myfree(p3);
    mymalloc_dump();
    myfree(p4);
    mymalloc_dump();
    myfree(p5);
    mymalloc_dump();
    return 0;
}
