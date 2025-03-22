#include <iostream>

int* CreateAr(int size) {
    // Выделение памяти для массива размером size
    int* array = new int[size];
    return array;  // Возвращаем указатель на первый элемент массива
}

int main() {
    int size = 9;
    int* myArray = CreateAr(size);  // Создаем массив

    // Используем массив
    for (int i = 0; i < size; ++i) {
        myArray[i] = i * 10;  // Заполняем массив значениями
    }

    // Выводим значения массива
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    // Освобождаем память
    delete[] myArray;

    return 0;
}
