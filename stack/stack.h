#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>
#include <string.h>

struct stack_t {
    void (*push)(struct stack_t*, void*);
    void* (*pop)(struct stack_t*);
    void* (*peek)(struct stack_t*);
    char *data;
    size_t dsz;
    int size;
    int max;
};

struct stack_t * make_stack(size_t dsz);
void free_stack(struct stack_t *stack);

#endif