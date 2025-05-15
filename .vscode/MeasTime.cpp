// MeasTime.cpp
#include "MeasTime.h"
#include <iostream>

// Реализация функции для измерения времени выполнения
template <typename Func>
double measureTime(Func sortFunc, int* ar, int size, bool isAscending) {
    auto start = std::chrono::high_resolution_clock::now();

    // Вызов функции сортировки
    sortFunc(ar, size, isAscending);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

// Явное инстанцирование шаблона для конкретных типов функций
template double measureTime(void (*)(int*, int, bool), int*, int, bool);
