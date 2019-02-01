#include <stdio.h>
#include "stack.h"

void copy(void *array, void *data) {
  array += 4;
  memcpy(array, data, 4);
  array -= 4;
}

int main() {
  struct stack_t *stk = make_stack(sizeof(int));

  for (int i = 100000; i > 0; i--) {
    // int r = rand();
    printf("Pushing %d to the stack\n", i);
    stk->push(stk, &i);
  }

  while (stk->size) {
    int y = *((int *)stk->pop(stk));
    printf("Popping %d from the stack\n", y);
  }

  free_stack(stk);
  return 0;
}
