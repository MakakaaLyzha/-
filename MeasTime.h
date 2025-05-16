// MeasTime.h
#ifndef MEAS_TIME_H
#define MEAS_TIME_H

#include <chrono>
#include <functional>

// Функция для измерения времени выполнения функции сортировки
template <typename Func>
double measureTime(Func sortFunc, int* ar, int size, bool isAscending);

#endif // MEAS_TIME_H
