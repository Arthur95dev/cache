#include "../src/deque.h"
#include "../src/deque.c" // Добавляем из-за скрытой реализации Deque и Node

#include <check.h>

// Проверка инициализации
START_TEST(test_init) {
  struct Deque* list = deque_init();

  ck_assert_ptr_eq(list->head, NULL);
  ck_assert_ptr_eq(list->tail, NULL);
  ck_assert_int_eq(list->len, 0);
}
END_TEST

// Проверка добавления в конец списка
START_TEST(test_push_back) {
  struct Deque* list = deque_init();
  push_back(list, 100);
  
  ck_assert_int_eq(list->tail->value, 100);
  ck_assert_int_eq(list->len, 1);
}
END_TEST

// Проверка добавления в начало списка
START_TEST(test_push_front) {
  struct Deque* list = deque_init();
  push_front(list, 200);

  ck_assert_int_eq(list->head->value, 200);
  ck_assert_int_eq(list->len, 1);
}
END_TEST

// Проверка удаления из конца списка
START_TEST(test_pop_back) {
  struct Deque* list = deque_init();
  push_back(list, 100);
  push_back(list, 200);

  pop_back(list);

  ck_assert_int_eq(list->tail->value, 100);
}
END_TEST

// Проверка удаления из начала списка
START_TEST(test_pop_front) {
  struct Deque* list = deque_init();
  push_back(list, 100);
  push_back(list, 200);

  pop_front(list);

  ck_assert_int_eq(list->head->value, 200);
}
END_TEST

Suite* deque_suite() {
  // Создаём тестовый набор, т.к тестируем двусвязный список, название набора Deque
  Suite* s = suite_create("Deque");

  // Создаём тестовую группу, т.к тестируем основные функции, название группы Core
  TCase* tc_core = tcase_create("Core");

  // Добавляем тесты в тестовую группу
  tcase_add_test(tc_core, test_init);
  tcase_add_test(tc_core, test_push_back);
  tcase_add_test(tc_core, test_push_front);
  tcase_add_test(tc_core, test_pop_back);
  tcase_add_test(tc_core, test_pop_front);

  // Добавляем тестовую группу Core в наш тестовый набор
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
    int failed_tests_count;
    
    Suite* s = deque_suite();
    SRunner* runner = srunner_create(s);

    // Запуск всех тестов
    srunner_run_all(runner, CK_NORMAL);

    // Проверка результатов
    failed_tests_count = srunner_ntests_failed(runner);

    // Освобождаем память
    srunner_free(runner);

    return failed_tests_count;
}
