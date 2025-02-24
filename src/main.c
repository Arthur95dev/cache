// Для вызова функции printf
#include <stdio.h>

#include "deque.c"
#include "deque.h"

int main() {
  struct Deque* list = deque_init();
  
  printf("Hello world!\n");
  
  return 0;
}
