#include <iostream>
#include <cstdlib> // Для функции rand()
#include <ctime>   // Для функции time()

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
void getInfoArray(struct ArrayInfo* arInfo) {
    if (arInfo->size <= 0 || arInfo->ar == nullptr) return;

    int sum = 0;
    arInfo->ind_max = 0;
    arInfo->ind_min = 0;

    for (int i = 0; i < arInfo->size; ++i) {
        sum += arInfo->ar[i];
        if (arInfo->ar[i] > arInfo->ar[arInfo->ind_max]) {
            arInfo->ind_max = i;
        }
        if (arInfo->ar[i] < arInfo->ar[arInfo->ind_min]) {
            arInfo->ind_min = i;
        }
    }

    arInfo->mean = static_cast<double>(sum) / arInfo->size;
}

// Функция для поиска минимального и максимального элементов
struct MinMax GetMaxMin(const int* ar, int size) {
    struct MinMax result = {0, 0};
    if (size <= 0 || ar == nullptr) return result;

    result.ind_min = 0;
    result.ind_max = 0;

    for (int i = 0; i < size; ++i) {
        if (ar[i] > ar[result.ind_max]) {
            result.ind_max = i;
        }
        if (ar[i] < ar[result.ind_min]) {
            result.ind_min = i;
        }
    }

    return result;
}


struct CountNum GetStatNumber(const int* ar, int size) {
    struct CountNum result = {0, 0, 0};
    if (size <= 0 || ar == nullptr) return result;

    for (int i = 0; i < size; ++i) {
        if (ar[i] > 0) {
            result.pos++;
        } else if (ar[i] < 0) {
            result.neg++;
        } else {
            result.zero++;
        }
    }

    return result;
}

int main() {
    int size = 5;
    int* array = new int[size]{-1, 0, 2, -3, 4};

    struct ArrayInfo arInfo;
    arInfo.ar = array;
    arInfo.size = size;

    getInfoArray(&arInfo);

    std::cout << "Index of max element: " << arInfo.ind_max << std::endl;
    std::cout << "Index of min element: " << arInfo.ind_min << std::endl;
    std::cout << "Mean value: " << arInfo.mean << std::endl;

    struct MinMax mm = GetMaxMin(array, size);
    std::cout << "Index of max element (from GetMaxMin): " << mm.ind_max << std::endl;
    std::cout << "Index of min element (from GetMaxMin): " << mm.ind_min << std::endl;

    struct CountNum cn = GetStatNumber(array, size);
    std::cout << "Positive numbers: " << cn.pos << std::endl;
    std::cout << "Negative numbers: " << cn.neg << std::endl;
    std::cout << "Zeros: " << cn.zero << std::endl;

    delete[] array;
    return 0;
}
