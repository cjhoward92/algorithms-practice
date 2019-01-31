#include "stack.h"

int main() {
  struct stack_t *stk = make_stack(sizeof(int));

  int x = 10;
  stk->push(stk, (void*)(&x));

  free_stack(stk);
  return 0;
}