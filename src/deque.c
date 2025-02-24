#include "deque.h"

struct Node {
  struct Node* next;
  struct Node* prev;
  int value;
};

struct Deque {
  struct Node* head;
  struct Node* tail;
  int len;
};

struct Deque* deque_init() {
  struct Deque* list = (struct Deque*)malloc(sizeof(struct Deque));

  list->head = NULL;
  list->tail = NULL;
  list->len = 0;
  
  return list;
};

void push_back(struct Deque* list, int value) {
  struct Node* newNode = malloc(sizeof(struct Node));
  if (!newNode) return;

  newNode->value = value;
  newNode->prev = list->tail;
  newNode->next = NULL;

  if (!list->len) {
    list->head = newNode;
    list->tail = newNode;
  }
  
  list->tail->next = newNode;
  list->tail = newNode;
  list->len++;
};

void push_front(struct Deque* list, int value) {
  struct Node* newNode = malloc(sizeof(struct Node));
  if (!newNode) return;

  newNode->value = value;
  newNode->prev = NULL;
  newNode->next = list->head;

  if (!list->len) {
    list->head = newNode;
    list->tail = newNode;
  } 
 
  list->head->prev = newNode;
  list->head = newNode;
  list->len++;
};

bool pop_back(struct Deque *list) {
  if (!list->len) return false;

  struct Node* tmp = list->tail;

  // Возможно будем возвращать
  int value = tmp->value;

  list->tail = list->tail->prev;

  // На случай, если после удаления список стал пустым
  if (list->tail) {
    list->tail->next = NULL;
  } else {
    list->head = NULL;
  }

  free(tmp);
  list->len--;
  return true;
};

bool pop_front(struct Deque* list) {
  if (!list->len) return false;

  struct Node* tmp = list->head;

  // Возможно будем возвращать
  int value = tmp->value;
  
  list->head = list->head->next;

  // На случай, если после удаления список стал пустым
  if (list->head) {
    list->head->prev = NULL; 
  } else {
    list->tail = NULL;
  }

  free(tmp);
  list->len--;
  return true;
};

void clear_list(struct Deque *list) {
  // Очищаем список
  while(list->head) pop_front(list);
}
