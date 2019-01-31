#include "stack.h"

int main() {
  struct stack_t *stk = make_stack(sizeof(int));

  int *x = malloc(sizeof(int));
  *x = 10;
  stk->push(stk, x);

  free_stack(stk);
  return 0;
}