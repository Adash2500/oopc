int mymalloc_init(unsigned long size);
void* mymalloc(unsigned long size);
void myfree(void* ptr);
void* myrealloc(void* ptr, unsigned long size);
void mymalloc_dump(void);
