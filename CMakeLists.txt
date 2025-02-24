cmake_minimum_required(VERSION 3.10)  # Минимальная версия CMake

project(cache)  # Имя проекта

set(CMAKE_CXX_STANDARD 17)  # Указываем стандарт C++
set(CMAKE_CXX_STANDARD_REQUIRED True)  # Обязательное использование стандарта

enable_testing()

# Создаём исполняемый файл для основной программы(пока что основная программа это двусвязный список)
add_executable(cache src/main.c)
target_include_directories(cache PRIVATE src/)

# Создаём исполняемый файл для тестов
add_executable(deque_tests tests/deque_tests.c)
target_include_directories(deque_tests PRIVATE src/)

# Указываем путь к заголовочным файлам Check для тестового модуля deque_tests
target_include_directories(deque_tests PRIVATE /usr/include/check)

# Линкуем библиотеки Check
target_link_libraries(deque_tests /usr/lib/x86_64-linux-gnu/libcheck.a m pthread)
target_link_libraries(deque_tests /usr/lib/x86_64-linux-gnu/libsubunit.a m pthread)

# Добавляем тесты для модуля CTest
add_test(NAME Tests COMMAND deque_tests)
