#include <iostream>
#include <cstdlib>
#include <algorithm>

// Структура для хранения массива и вероятностей
struct StatArray {
    int* ar;           // Массив, содержащий число элементов
    int size;          // Число элементов массива
    double* probabilities; // Вероятности
    int size_prob;     // Размер выделенной памяти для вероятностей
};

// Функция для создания массива
int* CreateAr(int size) {
    return new int[size];
}

// Функция для вычисления вероятностей
StatArray GetStatArray(const int* ar, int size) {
    StatArray statArray;
    statArray.size = size;
    statArray.ar = new int[size];
    std::copy(ar, ar + size, statArray.ar);

    // Найти максимальный элемент в массиве
    int maxElement = *std::max_element(ar, ar + size);
    statArray.size_prob = maxElement + 1;
    statArray.probabilities = new double[statArray.size_prob]();

    // Подсчет количества каждого элемента
    for (int i = 0; i < size; ++i) {
        statArray.probabilities[ar[i]] += 1.0;
    }

    // Вычисление вероятностей
    for (int i = 0; i < statArray.size_prob; ++i) {
        statArray.probabilities[i] /= size;
    }

    return statArray;
}

// Функция сортировки вставками
void insertion_sort(int* ar, int size, bool isAscending) {
    for (int i = 1; i < size; ++i) {
        int key = ar[i];
        int j = i - 1;

        if (isAscending) {
            while (j >= 0 && ar[j] > key) {
                ar[j + 1] = ar[j];
                j = j - 1;
            }
        } else {
            while (j >= 0 && ar[j] < key) {
                ar[j + 1] = ar[j];
                j = j - 1;
            }
        }
        ar[j + 1] = key;
    }
}

// Функция пузырьковой сортировки
void bubble_sort(int* ar, int size, bool isAscending) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if ((isAscending && ar[j] > ar[j + 1]) || (!isAscending && ar[j] < ar[j + 1])) {
                std::swap(ar[j], ar[j + 1]);
            }
        }
    }
}

int main() {
    // Пример использования функции GetStatArray
    int size = 15;
    int* ar = CreateAr(size);
    int data[] = {0, 1, 2, 3, 4, 5, 0, 1, 1, 1, 2, 3, 0, 9, 10};
    std::copy(data, data + size, ar);

    StatArray statArray = GetStatArray(ar, size);

    std::cout << "Probabilities:" << std::endl;
    for (int i = 0; i < statArray.size_prob; ++i) {
        std::cout << "P" << i << " = " << statArray.probabilities[i] << std::endl;
    }

    // Освобождение памяти
    delete[] ar;
    delete[] statArray.ar;
    delete[] statArray.probabilities;

    // Пример использования функций сортировки
    int sortSize = 5;
    int* sortAr = CreateAr(sortSize);
    int sortData[] = {5, 3, 4, 1, 2};
    std::copy(sortData, sortData + sortSize, sortAr);

    std::cout << "\nOriginal array: ";
    for (int i = 0; i < sortSize; ++i) {
        std::cout << sortAr[i] << " ";
    }
    std::cout << std::endl;

    insertion_sort(sortAr, sortSize, true);
    std::cout << "After insertion sort (ascending): ";
    for (int i = 0; i < sortSize; ++i) {
        std::cout << sortAr[i] << " ";
    }
    std::cout << std::endl;

    bubble_sort(sortAr, sortSize, false);
    std::cout << "After bubble sort (descending): ";
    for (int i = 0; i < sortSize; ++i) {
        std::cout << sortAr[i] << " ";
    }
    std::cout << std::endl;

    delete[] sortAr;

    return 0;
}
