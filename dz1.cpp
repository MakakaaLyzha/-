#include <iostream>

// Функция для вывода чисел из массива в обратном порядке
void ShowNum_reverse(const int* array, size_t size_ar) {
    for (size_t i = size_ar; i-- > 0;) {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}

// Функция для вывода чисел из массива в прямом порядке
void ShowNum(const int* array, size_t size_ar) {
    for (size_t i = 0; i < size_ar; ++i) {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}

// Функция для вывода только четных чисел из массива
void ShowEven(const int* array, size_t size_ar) {
    for (size_t i = 0; i < size_ar; ++i) {
        // Проверка на четность без использования операции %
        if ((array[i] & 1) == 0) {
            std::cout << array[i] << "\t";
        }
    }
    std::cout << std::endl;
}

// Основная функция
int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t size_ar = sizeof(array) / sizeof(array[0]);

    std::cout << "Числа в обратном порядке:" << std::endl;
    ShowNum_reverse(array, size_ar);

    std::cout << "Числа в прямом порядке:" << std::endl;
    ShowNum(array, size_ar);

    std::cout << "Только четные числа:" << std::endl;
    ShowEven(array, size_ar);

    return 0;
}
