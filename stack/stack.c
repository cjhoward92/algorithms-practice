#include "stack.h"

#define INIT_ARRAY_SIZE 8

static void push(struct stack_t *stack, void* data) {
  memcpy(stack->data[stack->size++ * stack->dsz], data, stack->dsz);

  if (stack->size > stack->max / 2)
    grow_stack(stack);
}

static void * pop(struct stack_t *stack) {
  if (!stack->size)
    return NULL;

  char data[stack->dsz];
  memcpy(data, stack->data[(stack->size - 1) * stack->dsz], stack->dsz);
  stack->data -= stack->dsz;
  stack->size--;

  if (stack->size < stack->max / 4)
    shrink_stack(stack);

  return data;
}

static void * peek(struct stack_t *stack) {
  if (!stack->size)
    return NULL;

  char data[stack->dsz];
  memcpy(data, stack->data[(stack->size - 1) * stack->dsz], stack->dsz);
  return data;
}

static void grow_stack(struct stack_t *stack) {
  
}

static void shrink_stack(struct stack_t *stack) {

}

struct stack_t * make_stack(size_t dsz) {
  struct stack_t *stack = (struct stack_t *)malloc(sizeof(struct stack_t));
  stack->push = &push;
  stack->pop = &pop;
  stack->peek = &peek;
  stack->dsz = dsz;
  stack->size = 0;

  // Initialize empty array
  stack->data = malloc(INIT_ARRAY_SIZE * dsz);
  memset(stack->data, 0, INIT_ARRAY_SIZE * dsz);
  stack->max = INIT_ARRAY_SIZE;
}

void free_stack(struct stack_t *stack) {
  // Free all our data
  free(stack->data);
  free(stack);
}