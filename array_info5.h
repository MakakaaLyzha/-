#ifndef ARRAY_INFO_H
#define ARRAY_INFO_H

// Структура для хранения массива и вероятностей
struct StatArray {
    int* ar;           // Массив, содержащий число элементов
    int size;          // Число элементов массива
    double* probabilities; // Вероятности
    int size_prob;     // Размер выделенной памяти для вероятностей
};

// Функция для создания массива
int* CreateAr(int size);

// Функция для вычисления вероятностей
StatArray GetStatArray(const int* ar, int size);

#endif // ARRAY_INFO_H
