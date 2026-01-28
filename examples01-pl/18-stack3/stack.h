struct stack_handle;

void push(struct stack_handle* s, int a);
int pop(struct stack_handle* s);
void clear(struct stack_handle* s);
struct stack_handle* init(void);
void finalize(struct stack_handle* s);
