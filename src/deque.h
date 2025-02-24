#ifndef DEQUE_H
#define DEQUE_H

// Для использования bool type
#include <stdbool.h>

// Для выделения памяти - функция malloc
// и очищения памяти - функция free
#include <stdlib.h>

struct Node;
struct Deque;

struct Deque* deque_init();
void clear_list(struct Deque* list);

void push_back(struct Deque* list, int value);
void push_front(struct Deque* list, int value);

bool pop_back(struct Deque* list);
bool pop_front(struct Deque *list);

#endif
