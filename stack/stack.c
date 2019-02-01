#include <stdio.h>
#include "stack.h"

#define GROW_PTR(ptr,sz) ptr += sz
#define SHRINK_PTR(ptr,sz) ptr -= sz

static void grow_stack(struct stack_t *stack) {
  if (!stack || stack->size < stack->max)
    return;

  stack->max *= 2;

  void* new_data = malloc(stack->max * stack->dsz);
  memmove(new_data, stack->head, stack->size * stack->dsz);

  // Cleanup old head.
  free(stack->head);

  stack->head = new_data;
  stack->data = stack->head + (stack->size * stack->dsz);
}

static void shrink_stack(struct stack_t *stack) {
  if (!stack || stack->max == (stack->dsz * 2) || stack->size > stack->max / 4)
    return;

  stack->max /= 2;

  void* new_data = malloc(stack->max * stack->dsz);
  memmove(new_data, stack->head, stack->size * stack->dsz);

  // Cleanup old head.
  free(stack->head);

  stack->head = new_data;
  stack->data = stack->head + (stack->size * stack->dsz);
}

static void push(struct stack_t *stack, const void* data) {
  if (!stack || !data)
    return;

  memcpy(stack->data, data, stack->dsz);
  stack->size++;
  
  GROW_PTR(stack->data, stack->dsz);
  grow_stack(stack);
}

static void * pop(struct stack_t *stack) {
  if (!stack || !stack->size)
    return NULL;

  SHRINK_PTR(stack->data, stack->dsz);
  void *ptr = stack->data;
  stack->size--;

  //printf("going to shrink\n");
  shrink_stack(stack);
  //printf("shrunk\n");

  return ptr;
}

static void * peek(struct stack_t *stack) {
  if (!stack || !stack->size)
    return NULL;

  return (void *)stack->data;
}

struct stack_t * make_stack(size_t dsz) {
  struct stack_t *stack = (struct stack_t *)malloc(sizeof(struct stack_t));
  stack->push = &push;
  stack->pop = &pop;
  stack->peek = &peek;
  stack->dsz = dsz;
  stack->size = 0;

  // Initialize empty array
  size_t init_size = dsz * 2;
  stack->data = malloc(init_size * dsz);
  memset(stack->data, 0, init_size * dsz);

  stack->max = init_size;
  stack->head = stack->data;
}

void free_stack(struct stack_t *stack) {
  // We need to reset to the head (just in case the LIFO stack isn't empty)
  stack->data = stack->head;

  stack->size = 0;
  stack->dsz = 0;
  
  free(stack->data);
  stack->data = NULL;
  stack->head = NULL;

  free(stack);
}