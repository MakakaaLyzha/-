#ifndef ARRAY_INFO_H
#define ARRAY_INFO_H

// Структура для хранения информации о массиве
struct ArrayInfo {
    int* ar;          // Адрес первого элемента массива
    int size;         // Размер массива
    int ind_max;      // Индекс элемента с максимальным значением
    int ind_min;      // Индекс элемента с минимальным значением
    double mean;      // Среднее арифметическое значение массива
};

// Структура для хранения индексов минимального и максимального элементов
struct MinMax {
    int ind_min;
    int ind_max;
};

// Структура для подсчета положительных, отрицательных чисел и нулей
struct CountNum {
    int pos;
    int neg;
    int zero;
};

// Функция для заполнения структуры ArrayInfo
void getInfoArray(struct ArrayInfo* arInfo);

// Функция для поиска минимального и максимального элементов
struct MinMax GetMaxMin(const int* ar, int size);

// Функция для подсчета положительных, отрицательных чисел и нулей
struct CountNum GetStatNumber(const int* ar, int size);

#endif // ARRAY_INFO_H
